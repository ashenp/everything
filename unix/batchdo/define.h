#include <string>
#ifndef _DEFINE_H
#define _DEFINE_H

#ifndef CONF_PATH 
#define CONF_PATH "/etc/batchdo/batchdo.yaml"
#endif

#define BATCHDO_SUCCESS 0

#define BATCHDO_FAILED 1

#define __log(...)                  \
    do                              \
    {                               \
        printf(__VA_ARGS__);     \
    } while(0)      
 
#define __format(__fmt__) "[%s:%d] " __fmt__ "\n"
 
#define LOG(__fmt__, ...)                          \
    do                                                     \
    {                                                      \
        __log(__format(__fmt__), __FILE__, __LINE__, ##__VA_ARGS__);  \
    } while(0)

#endif
