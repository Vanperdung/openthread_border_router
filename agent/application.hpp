#ifndef __APPLICATION_HPP__
#define __APPLICATION_HPP__

#include "code_utils.hpp"
#include "types.hpp"

namespace otbr {


/**
 * This class implements OTBR application management.
 *
 */
class Application : private NonCopyable
{
public:
    explicit Application(const std::string               &aInterfaceName,
                         const std::vector<const char *> &aBackboneInterfaceNames,
                         const std::vector<const char *> &aRadioUrls,
                         bool                             aEnableAutoAttach,
                         const std::string               &aRestListenAddress,
                         int                              aRestListenPort);

    void Init(void);

    void Deinit(void);

    otbrError Run(void);


};

} // namespace otbr
#endif