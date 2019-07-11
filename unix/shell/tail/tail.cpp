#include "tail.hpp"
#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

string parse_str = "n:f";
int static_tail = 0;
int line_num;
string file_name;
void usage() {
    string x =  "Usage:                                    \n \
    tailf [option] file                                    \n \
                                                           \n \
    Options:                                               \n \
      -n NUMBER  output the last NUMBER lines              \n \ 
      -f continuously get the end of file                  \n \
    Default:                                               \n \
      run as tail -f FILE if didn't be set any option";
    cout << x << endl;
}

int main(int argc, char** argv) {
    int opt;
    while( (opt = getopt(argc, argv, parse_str.c_str())) != -1 ) {
        switch(opt) {
            case 'f':  
                break;
            case 'n':
                static_tail = 1;
                line_num = atoi(optarg);
                break;
            deftult:
                break;
        }
    } 
    if(optind < 1) {
        usage(); 
        return 0;
    }
    
    file_name = argv[optind]; 
    FileReader* f_reader = new FileReader(file_name);
    if(static_tail) {
        string output = f_reader->get_last_lines(line_num);
        cout << output;
    } else {
        f_reader->tailf();
    }
    return 0; 
}
