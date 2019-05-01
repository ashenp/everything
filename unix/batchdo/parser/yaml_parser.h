#ifndef _YAML_PARSER_H
#define _YAML_PARSER_H

#include "parser.h"

class Yaml_Parser : public Parser {
public:
    Yaml_Parser();
    int parse(map<string, int>& server_vec);

private:
    string _conf_path;
};

extern Yaml_Parser yaml_parser;

#endif
