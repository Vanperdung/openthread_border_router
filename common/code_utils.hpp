#ifndef __CODE_UTILS_HPP__
#define __CODE_UTILS_HPP__

#define ExitNow(...)        \ 
    do                      \
    {                       \
        ret = __VA_ARGS__;  \
        goto exit;          \
    } while(0)              \

#endif