#ifndef __LOGGING_HPP__
#define __LOGGING_HPP__

typedef enum
{
    OTBR_LOG_EMERG,   ///< System is unusable
    OTBR_LOG_ALERT,   ///< Action must be taken immediately
    OTBR_LOG_CRIT,    ///< Critical conditions
    OTBR_LOG_ERR,     ///< Error conditions
    OTBR_LOG_WARNING, ///< Warning conditions
    OTBR_LOG_NOTICE,  ///< Normal but significant condition
    OTBR_LOG_INFO,    ///< Informational
    OTBR_LOG_DEBUG,   ///< Debug level messages    
} otbrLogLevel;



#endif