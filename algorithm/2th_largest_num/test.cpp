#include <iostream>
#include "include/find.hpp"

int main(int argc, char** argv) {
    std::vector<int> vec = {1,8,3,4}; 
    int res = find(vec);  
    std::cout << res << std::endl;
    return 0;
}



