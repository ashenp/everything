#include "tailf.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;



int main(int argc, char** argv) {
    ofstream write; 
    write.open("test.txt", ios::app);
    while(true) {
        write << "xxxxxxxxxxxxxxx" << endl; 
        write << "yyyyyyyyyyyyyyy" << endl; 
        usleep(5*1000); 
    }
    return 0; 
}
