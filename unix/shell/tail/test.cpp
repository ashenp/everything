#include "tailf.hpp"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    string res;
    FileReader* f_reader = new FileReader("test.txt");
    res = f_reader->get_last_lines(2);
    cout << res;
    return 0; 
}
