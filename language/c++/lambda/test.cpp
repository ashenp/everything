#include <iostream>


int main(int argc, char** argv) {

    int x = 0;
    int y = 42;
    
    auto qqq = [x, &y] {
        std::cout << "x:"  << x << std::endl;        
        std::cout << "y:"  << y << std::endl;        
        ++y;
    };
    x = y = 77;
      
    qqq();
    qqq();
    

    
    std::cout << "finally x:"  << x << std::endl;        
    std::cout << "finally y:"  << y << std::endl;        
    return 0;


}
