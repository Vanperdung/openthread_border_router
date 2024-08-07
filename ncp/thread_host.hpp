#ifndef __THREAD_HOST_HPP__
#define __THREAD_HOST_HPP__

#include "openthread/thread.h"
#include "lib/spinel/coprocessor_type.h"
#include "logging.hpp"

namespace otbr {
namespace Ncp {

class NetworkProperties
{
public:
    // Return the device role
    virtual otDeviceRole GetDeviceRole(void) const = 0;

    virtual ~NetworkProperties(void) = default;
};

class ThreadHost : virtual public NetworkProperties
{
public:
    /*
    * Define a alias for a std::function which has two arguments
    * otError and otDeviceRole. The return value type is void
    */ 
    using GetRoleHandler = std::function<void(otError, otDeviceRole);


    // Create a Thread Controller Instance
    static std::unique_ptr<ThreadHost> Create(const char                      *aInterfaceName,
                                              const std::vector<const char *> &aRadioUrls,
                                              const char                      *aBackboneInterfaceName,
                                              bool                             aDryRun,
                                              bool                             aEnableAutoAttach)

    // Returns the co-processor type
    virtual CoprocessorType GetCoprocessorType(void) = 0;

    // Returns the co-processor version string
    virtual const char *GetCoprocessorVerison(void) = 0;

    virtual const char *GetInterfaceName(void) = 0;

    virtual void Init(void) = 0;

    virtual void Deinit(void) = 0;

    virtual ~ThreadHost(void) = default;

protected:
    static otLogLevel ConvertToOtLogLevel(otbrLogLevel aLevel);
};

}
} // namespace otbr


#endif