#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include "code_utils.hpp"

/**
 * This class implements OTBR application management.
 *
 */
class Application : private NonCopyable
{
public:
    Application(void) = default;
    Application(const Application& _app)
    {}
};


#endif