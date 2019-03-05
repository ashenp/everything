#include <iostream>
#include <thread>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


using namespace std;

void loop(char* dest, const char* c_) {
    while(true) {
        strcpy(dest, c_); 
    }
}


int main(int argc, char* argv[]) {
    char* c = (char*)malloc(C_SIZE);     

    thread t1(loop, c, C_STRING_1); 
    thread t2(loop, c, C_STRING_2);
    
    t1.detach();
    t2.detach();
    
    while(true) {
        cout << c << endl;    
    }  
    return 0;
}
