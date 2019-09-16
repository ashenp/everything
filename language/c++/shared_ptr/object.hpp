#ifndef _EVERYTHING_LANGUAGE_CPLUSPLUS_OBJECT
#define _EVERYTHING_LANGUAGE_CPLUSPLUS_OBJECT
#include <iostream>

class Object{
    
public:

    Object() {
        std::cout << "Object construct function called " << std::endl;
    }
    
    ~Object() {
        std::cout << "Object destruct function called " << std::endl;
    }

};

#endif
