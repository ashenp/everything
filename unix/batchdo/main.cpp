#include <iostream>
#include <sstream>
#include <string>
#include <parser.h>
#include <getopt.h>
#include <cstring>
#include <batchdo.h>

using namespace std;
static string cmd;
static string group;
static string type;
static string config;

static string str = "";

int main(int argc, char* argv[]) {
    int opt;
    int opt_index;

    struct option long_options[] = {
        {"type",     required_argument, 0,   0},
        {"group",     required_argument, 0,  0},
        {"cmd",     required_argument, 0,    0},
        {"config",  optional_argument,  0,    0},
        {0,         0,                 0,    0}
    };   

    while( (opt = getopt_long(argc, argv, str.c_str(), long_options, &opt_index)) != -1) {
        switch(opt_index) {
            case 0:
            type = optarg;
            break;
            case 1:
            group = optarg;
            break;
            case 2:
            cmd = optarg;
            break;
            case 3:
            config = optarg;
            break;
        }
    } 
    
    stringstream ss;
    Batchdo ins(type, group, cmd, config);
    ins.run(ss);
    return 0;
}


