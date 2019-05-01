#include <iostream>
#include "yaml-cpp/yaml.h"
#include "parser/yaml_parser.h"
#include "parser.h"

Yaml_Parser yaml_parser;

Yaml_Parser::Yaml_Parser() {

}

int Yaml_Parser::parse(map<string, int>& server_vec) {
    if(group.empty()) {
        LOG("error with out group name"); 
        return BATCHDO_FAILED;
    }
    //do nothing 

    YAML::Node yaml_config_node;
    try {
        yaml_config_node = YAML::LoadFile(config);
    }catch (exception& e) {
        LOG("error when loading yaml config:%s, err_msg:%s", config.c_str(), e.what()); 
        return BATCHDO_FAILED;
    }

    
    if(const YAML::Node group_node = yaml_config_node[group.c_str()]) {
        for(unsigned int i = 0; i < group_node.size(); i++) {
            string ip;
            int port;
            ip =  group_node[i]["IP"].as<string>();
            port =  group_node[i]["Port"].as<int>();
            server_vec.insert(make_pair(ip, port));
        }   
    } else {
        LOG("couldn't find the group:%s" , group.c_str());
        return BATCHDO_FAILED;
    }
    if(server_vec.empty()) {
        LOG("server empty");
        return BATCHDO_FAILED; 
    } 

    return BATCHDO_SUCCESS;
}


