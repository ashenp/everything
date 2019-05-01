#ifndef _PARSER_H
#define _PARSER_H

#include <vector>
#include <map>
#include <string>
#include <sstream>
#include "define.h"

using namespace std;



void register_parser();

void init_env();

class Parser{
public:
    void set_config(const string config_) {
        config = config_; 
    }

    void set_group(const string group_) {
        group = group_; 
    }

    virtual int parse(map<string, int>& server_vec)  = 0; 
public:

    string group;

    string config;
    
};

extern map<string, Parser*> map_parser;

#endif
