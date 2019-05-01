#include "parser.h"
#include "parser/yaml_parser.h"

using namespace std;

map<string, Parser*> map_parser;

void register_parser() {
    map_parser.insert(make_pair("yaml", &yaml_parser));
}

void init_env() {
    register_parser();
}



