#include "tailf.hpp"
#include <string>
#include <iostream>

using namespace std;



int main(int argc, char** argv) {
    string res;
    FileReader* f_reader = new FileReader("test.txt");
    f_reader->tailf();
    return 0; 
}
