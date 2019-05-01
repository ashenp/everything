#ifndef _BATCHDO_H
#define _BATCHDO_H

#include <string>
#include <sstream>
#include <map>
#include <thread>

using namespace std;

class Batchdo{

public:
    Batchdo(const string type_, const string group_, const string cmd_, const string& config_) 
        : type(type_)
        , group(group_)
        , cmd(cmd_)  
        , config(config_) 
    {
    }
    
    void run(stringstream &ss);

    int prepare_env();
    
    int get_servers();
    
    int execute();

    void thread_execute(const map<string, string>& cmd_map);

public:
    string type;

    string group;

    string cmd;
    
    string config;
    
    string name;
    
private:
    map<string, string> _res_map;
    map<string, int> _server_map;

};

#endif
