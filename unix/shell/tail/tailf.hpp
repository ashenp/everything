#ifndef EVERY_THING_UNIX_SHELL_TAIL_HPP
#define EVERY_THING_UNIX_SHELL_TAIL_HPP
#include <string>
#include <fstream>
#include <iostream>


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
        int cur_num = 0; 
        int cur_space_pos = -1;
        int file_size = _fin.tellg();
        file_size++;

        int pos;
        while(true) {
            pos = _fin.tellg();
            char ch;
            _fin.get(ch);
            if(ch == '\n') {
                cur_num++; 
                if(cur_num == num+1) break;
            }
            _fin.seekg(-2, ios_base::cur);
             
            if(pos == 0) break;
        }
        if(pos == 0) {
            _fin.clear();
            _fin.seekg(0, ios_base::beg);
        }
        int length = file_size - pos;         
        char* tmp = new char[length];
        _fin.read(tmp, length);
        output = tmp;
        delete[] tmp;
        return output;
    }
    
private:
    ifstream _fin;
    string _file_path;
};


#endif
