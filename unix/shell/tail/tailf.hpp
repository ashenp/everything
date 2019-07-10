#ifndef EVERY_THING_UNIX_SHELL_TAIL_HPP
#define EVERY_THING_UNIX_SHELL_TAIL_HPP
#include <string>
#include <fstream>
#include <iostream> 
#include <sys/stat.h>
#include <unistd.h>
using namespace std;

class FileReader{
public:

    FileReader(const string& file_path) {
        _file_path = file_path;
        stat(_file_path.c_str(), &_stat);
        _last_pos = get_end_pos(); 
        _fin.close(); 
    }
    
    string get_last_lines(int num) {
        string output;
        _fin.open(_file_path);
        _fin.clear();
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
    
    bool is_modified() {
        struct stat buf;  
        stat(_file_path.c_str(), &buf);
        if (buf.st_mtime == _stat.st_mtime &&
            buf.st_size == _stat.st_size
        ) return false;
        _stat = buf; 
        return true;
    }
    
    int  get_end_pos() {
        _fin.open(_file_path);
        _fin.seekg(0, ios_base::end);
        int pos = _fin.tellg();
        return pos;
    }
     
    int tailf() {
        while (true) {
            if (is_modified()) {
                int new_pos = get_end_pos();
                _fin.clear();
                _fin.seekg(_last_pos, ios_base::beg);
                int length = new_pos - _last_pos;
                if(length < 0) {
                    _last_pos = new_pos;
                    continue;
                }
                char* tmp = new char[length];
                _fin.read(tmp, length);
                cout << tmp;
                delete[] tmp;
                _last_pos = new_pos;
            } 
            _fin.close();
            usleep(500*1000);
        } 
    }

private:
    int _last_pos;
    struct stat _stat;    
    ifstream _fin;
    string _file_path;
};


#endif
