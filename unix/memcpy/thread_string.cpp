#include <iostream>
#include <thread>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


using namespace std;
string c;

void loop_1() {
    while(true) {
        c = C_STRING_1;
    }
}

void loop_2() {
    while(true) {
        c = C_STRING_2;
    }
}


int main(int argc, char* argv[]) {

    thread t1(loop_1); 
    thread t2(loop_2);
    
    t1.detach();
    t2.detach();
    
    while(true) {
        cout << c << endl;    
    }  
    return 0;
}
