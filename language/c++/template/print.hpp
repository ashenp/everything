#ifndef _EVERYTHING_LANGUAGE_CPLUSPLUS_TEMPLATE
#define _EVERYTHING_LANGUAGE_CPLUSPLUS_TEMPLATE
#include <iostream>

void print() {

}

template <typename T, typename... Types>

void print (const T& firstArg, const Types&... args) {
    std::cout << firstArg << std::endl;
    print(args...);
}

#endif
