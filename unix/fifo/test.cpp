#include <iostream>
#include "include/fifocache.hpp"
#include <string>


int main(int argc, char* argv[]) {
    
    fifo_cache<std::string, std::string> cache(5); 
    cache.put("a", "a");
    cache.put("a", "aa");
    cache.output(); 
    cache.put("b", "b");
    cache.put("c", "c");
    cache.output(); 
    cache.put("d", "d");
    cache.put("e", "e");
    cache.put("f", "f");
    cache.put("f", "ff");
    cache.output(); 
    
    return 0;
}
