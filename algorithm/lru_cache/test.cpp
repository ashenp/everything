#include "lrucache.hpp"
#include <string>

using namespace std;

int main(int argc, char** argv) {

    LRUCache<string, string>* cache = new LRUCache<string, string>(5);  
    cache->put("a", "A");  
    cache->put("b", "B");
    cache->put("c", "C");
    cache->put("d", "D");
    cache->put("e", "E");
    cache->put("f", "F");

    //cache->put("a", "X");
    cache->output();
     


}
