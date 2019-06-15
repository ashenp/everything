#include <iostream>
#include "include/lrucache.hpp"
#include <string>
#include <thread>

lru_cache<int, int> cache(300);


void thread1() {
    for(int i = 1; i <= 100; i++) {
        cache.put(i, i); 
    } 
}

void thread2() {
    for(int i = 101; i <= 200; i++) {
        cache.put(i, i); 
    } 
}

int main(int argc, char* argv[]) {
    std::thread t1(thread1); 
    std::thread t2(thread2); 
    t1.join();
    t2.join();
    
    std::cout << cache.size() << std::endl;
    return 0;
}
