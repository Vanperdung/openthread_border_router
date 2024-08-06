#include <iostream>
#include <vector>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <setjmp.h>
#include <new>
#include <getopt.h>
#include "code_utils.hpp"
#include "application.hpp"

static constexpr char kAutoAttachDisableArg[] = "--auto-attach=0";
static char           sAutoAttachDisableArgStorage[sizeof(kAutoAttachDisableArg)];
static jmp_buf sResetJump;
static const char* kDefaultInterfaceName = "wpan0";
enum
{
    OTBR_OPT_BACKBONE_INTERFACE_NAME = 'B',
    OTBR_OPT_DEBUG_LEVEL             = 'd',
    OTBR_OPT_HELP                    = 'h',
    OTBR_OPT_INTERFACE_NAME          = 'I',
    OTBR_OPT_VERBOSE                 = 'v',
    OTBR_OPT_SYSLOG_DISABLE          = 's',
    OTBR_OPT_VERSION                 = 'V',
    OTBR_OPT_SHORTMAX                = 128,
    OTBR_OPT_RADIO_VERSION,
    OTBR_OPT_AUTO_ATTACH,
    OTBR_OPT_REST_LISTEN_ADDR,
    OTBR_OPT_REST_LISTEN_PORT,
};

static const struct option kOptions[] = {
    {"backbone-ifname", required_argument, nullptr, OTBR_OPT_BACKBONE_INTERFACE_NAME},
    {"debug-level", required_argument, nullptr, OTBR_OPT_DEBUG_LEVEL},
    {"help", no_argument, nullptr, OTBR_OPT_HELP},
    {"thread-ifname", required_argument, nullptr, OTBR_OPT_INTERFACE_NAME},
    {"verbose", no_argument, nullptr, OTBR_OPT_VERBOSE},
    {"syslog-disable", no_argument, nullptr, OTBR_OPT_SYSLOG_DISABLE},
    {"version", no_argument, nullptr, OTBR_OPT_VERSION},
    {"radio-version", no_argument, nullptr, OTBR_OPT_RADIO_VERSION},
    {"auto-attach", optional_argument, nullptr, OTBR_OPT_AUTO_ATTACH},
    {"rest-listen-address", required_argument, nullptr, OTBR_OPT_REST_LISTEN_ADDR},
    {"rest-listen-port", required_argument, nullptr, OTBR_OPT_REST_LISTEN_PORT},
    {0, 0, 0, 0}
};

std::vector<char *> AppendAutoAttachDisableArg(int argc, char *argv[])
{
	std::vector<char *> args(argv, argv + argc);
	std::vector<char *>::iterator new_end;

	// std::remove_if returns a new end of container
	new_end = std::remove_if(args.begin(), args.end(),[](const char *arg) {

	// std::string::rfind(str, pos)
	// str: a given character or a string is to be found
	// pos: a position where the search is to be done

	return arg != nullptr && std::string(arg).rfind("--auto-attach", 0) == 0; });

	// Delete empty elements
	args.erase(new_end, args.end());
	strcpy(sAutoAttachDisableArgStorage, kAutoAttachDisableArg);
	args.push_back(sAutoAttachDisableArgStorage);
	args.push_back(nullptr);

	return args;
}

static void OnAllocateFailed(void)
{
	printf("Allocate failure, exiting...");
	exit(1);
}

static int realmain(int argc, char *argv[])
{
	int opt;
	int ret = EXIT_SUCCESS;
	const char *interfaceName = kDefaultInterfaceName;
	std::vector<const char *> radioUrls;
	// std::new_handler ser_new_handler(std::new_handler new_p)
	// Create a new handler and returns the previously installed handler
	// This new_p function is called by allocation functions whenever a memory allocation attemp fails
	// The purpose of this method:
	//  1. make more memory available
	//  2. terminate this program
	//  3. throw exception
	std::set_new_handler(OnAllocateFailed);

	while ((opt = getopt_long(argc, argv, "B:d:hI:Vvs", kOptions, nullptr)) != -1)
	{
		switch (opt)
		{
			case OTBR_OPT_BACKBONE_INTERFACE_NAME:
				break;
			
			case OTBR_OPT_DEBUG_LEVEL:
				break;
			
			case OTBR_OPT_HELP:
				break;

			case OTBR_OPT_INTERFACE_NAME:
				interfaceName = optarg;
				break;

			case OTBR_OPT_VERBOSE:
				break;
			
			case OTBR_OPT_SYSLOG_DISABLE:
				break;
			
			case OTBR_OPT_VERSION:
				break;

			case OTBR_OPT_RADIO_VERSION:
				break;
			
			case OTBR_OPT_AUTO_ATTACH:
				break;
			
			case OTBR_OPT_REST_LISTEN_ADDR:
				break;

			case OTBR_OPT_REST_LISTEN_PORT:
				break;

			default:
				// TODO: Print help
				ExitNow(EXIT_FAILURE);
				break;
		}
	}

	for (int i = optind; i < argc; i++)
	{
		printf("Radio URL: %s\n", argv[i]);
		radioUrls.push_back(argv[i]);
	}

	{
		Application app;
		Application app2 = app;
	}

	exit:
		return ret;
}

int main(int argc, char *argv[])
{
	if (setjmp(sResetJump))
	{
		std::vector<char *> args = AppendAutoAttachDisableArg(argc, argv);
		
		// Ensure the program does not receive a SIGALRM unexpectedly.
		alarm(0);

		execvp(args[0], args.data());
	}

	return realmain(argc, argv);
}
