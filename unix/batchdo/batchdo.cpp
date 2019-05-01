#include "batchdo.h"
#include "parser.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>


void Batchdo::run(stringstream &ss) {

    
    register_parser();

    _server_map.clear(); 

    if(prepare_env() != BATCHDO_SUCCESS) {
        LOG("error when prepare environment");
        return; 
    }

    if(
        get_servers() == BATCHDO_FAILED
    ) {
        LOG("error when fetch servers");
        return; 
    }

    if (
        execute() == BATCHDO_FAILED
    ) {
        LOG("error when execute cmd");
        return;
    }
    
    return;
}

int Batchdo::prepare_env() {
    if(name.empty()) {
        name += getlogin(); 
    } 
    if(name.empty()) {
        LOG("error, could not get current username"); 
        return BATCHDO_FAILED;
    }

    if(cmd.empty()) {
        LOG("error, empty cmd"); 
        return BATCHDO_FAILED;
    }
    
    return BATCHDO_SUCCESS;
}


int Batchdo::get_servers() {
    
    map<string, Parser*>::iterator it;
    if(type.empty()) {
        if(map_parser.empty()) {
            LOG("no parser is registered");
            return BATCHDO_FAILED;
        } else {
            it = map_parser.begin();
            LOG("doesn\'t input type, use default type:%s", it->first.c_str()); 
        } 
    } else {
        it = map_parser.find(type);
        if(it == map_parser.end()) {
            LOG("no matched parser");
            return BATCHDO_FAILED;
        }
    }

    it->second->set_config(config);
    it->second->set_group(group);
    it->second->parse(_server_map);

    return BATCHDO_SUCCESS;
}

int Batchdo::execute() {
    map<string, string> cmd_map;
    for(map<string, int>::iterator it = _server_map.begin(); it != _server_map.end(); it++) {
        string tmp_cmd = "ssh -l ";
        tmp_cmd += name;
        tmp_cmd += " ";
        tmp_cmd += it->first;
        tmp_cmd += " ";
        tmp_cmd += " -p ";
        tmp_cmd += to_string(it->second);
        tmp_cmd += " ";
        tmp_cmd += cmd;
        cmd_map.insert(make_pair(it->first, tmp_cmd));
    }
    
    map<int, map<string, string> > thread_map;
    vector<thread> v;
    _res_map.clear();

    //every thread run 20 command at most
    for(map<string, string>::iterator it = cmd_map.begin(); it != cmd_map.end(); it++) {
        int key =  ( distance(it, cmd_map.begin()) ) % 20;
        thread_map[key];
        thread_map[key].insert(*it);
    } 

    for(map<int, map<string, string> >::iterator it = thread_map.begin(); it != thread_map.end(); it++) {
        thread t(
                    &Batchdo::thread_execute, 
                    this,
                    it->second
                ); 
        v.push_back(move(t));
    } 
    
    for(vector<thread>::iterator it = v.begin(); it != v.end(); it++) {
        it->join(); 
    }
    
    for(map<string, string>::iterator it = _res_map.begin(); it != _res_map.end(); it++) {
        cout << "\033[32m" << it->first << ":" << endl;
        cout << "\033[33m" << it->second << "\033[0m"<< endl; 
    }
    
    return BATCHDO_SUCCESS;
}

void Batchdo::thread_execute(const map<string, string>& cmd_map) {     
    
    for(map<string, string>::const_iterator it = cmd_map.begin(); it != cmd_map.end(); it++) {
        FILE* pipe = popen(it->second.c_str(), "r");
        if (!pipe) return;
        char buffer[128];
        std::string result = "";
        while(!feof(pipe)) {
            if(fgets(buffer, 128, pipe) != NULL) {
                result += buffer;
            }
        }
        _res_map.insert(make_pair(it->first, result));
        pclose(pipe);
    } 
}





















//get a parser by type




