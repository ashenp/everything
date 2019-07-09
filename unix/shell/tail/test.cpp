#include "tailf.hpp"
#include <string>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {

    FileReader f_reader("test.txt");
    cout <<  "x" << endl;
    string res = f_reader.get_last_lines(1);
    cout <<  "y" << endl;
    
    cout << res << endl;
    return 0; 
}
