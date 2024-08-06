#ifndef __CODE_UTILS_HPP__
#define __CODE_UTILS_HPP__

#include <assert.h>
#include <memory>
#include <stdlib.h>

#define VerifyOrExit(condition, ...)    \
    do                                  \
    {                                   \
        if (!condition)                 \
        {                               \
            __VA_ARGS__;                \
            goto exit;                  \
        }                               \
    } while (false)                     \



#define ExitNow(...)        \
    do                      \
    {                       \
        ret = __VA_ARGS__;  \
        goto exit;          \
    } while(0)              \

class NonCopyable
{
public: 
    NonCopyable(const NonCopyable &) = delete;
    NonCopyable &operator=(const NonCopyable &) = delete;

protected:
    NonCopyable(void);    
};

#endif