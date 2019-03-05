#include "everything/unix/memcpy/memcpy.h"
#include <string>
#include <cstring>
#include <iostream>
#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>


using namespace ::everything;
using namespace std;

int main(int argc, char* argv[]) { 
    Block* block_point = reinterpret_cast<Block*>(
        mmap(NULL, sizeof(Block*),  PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0)  
    );
    
    int pid_1 = fork();
    if (pid_1 < 0) {
        std::cout << "fork child_1 failed" << std::endl;
    } else if(pid_1 == 0){
        char tmp_1[C_SIZE];
        strcpy(tmp_1, C_STRING_1);
        while(true) {
            memcpy(block_point, tmp_1, sizeof(Block));
        }
    } else {
        std::cout << "fork child_1 success" << std::endl;
    }
        
    int pid_2 = fork();
    if (pid_2 < 0) {
        std::cout << "fork child_2 failed" << std::endl;
    } else if(pid_2 == 0) {
        char tmp_2[C_SIZE];
        strcpy(tmp_2, C_STRING_2);
        while(true) {
            memcpy(block_point, tmp_2, sizeof(Block));
        }
    } else {
        std::cout << "fork child_2 success" << std::endl;
    }
    
    char tmp[C_SIZE];
    memcpy(tmp, block_point, sizeof(Block));
    while(true) {
        usleep(rand() % 100 + 1);
        std::cout << "current value:" << tmp << std::endl;
    }

    return 0;  
}
