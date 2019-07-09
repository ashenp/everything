#ifndef EVERY_THING_UNIX_SHELL_TAIL_HPP
#define EVERY_THING_UNIX_SHELL_TAIL_HPP
#include <string>
#include <fstream>


using namespace std;

class FileReader{
public:

    FileReader(const string& file_path) {
        _file_path = file_path;
        _fin.open(_file_path);
    }
    
    string get_last_lines(int num) {
        string output;
        _fin.seekg(-1, ios_base::end);   
        char ch; 
        _fin.get(ch); 
        output += ch;
    }
    
private:
    ifstream _fin;
    string _file_path;
};


#endif
