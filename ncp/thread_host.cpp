#include "thread_host.hpp"
#include "openthread/logging.h"

namespace otbr {
namespace ncp {

std::unique_ptr<ThreadHost> ThreadHost::Create(const char                      *aInterfaceName,
                                               const std::vector<const char *> &aRadioUrls,
                                               const char                      *aBackboneInterfaceName,
                                               bool                             aDryRun,
                                               bool                             aEnableAutoAttach)
{

}

otLogLevel ThreadHost::ConvertToOtLogLevel(otbrLogLevel aLevel)
{

}

} // namespace ncp
} // namespace otbr