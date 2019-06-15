#ifndef _MYSTRING_H
#define _MYSTRING_H

#include <istream>
#include <cstring>

using namespace std;

class String {

public:
    String(const char* str = nullptr) 
    {
        if(!str) {
            data = new char[1]; 
            length = 0;
            *data = '\0';
        } else {
            length = strlen(str);
            data = new char[length+1];
            strcpy(data, str); 
        }
    }

    String(const String& str) {
        length = str.size();  
        data = new char[length+1];
        strcpy(data, str.c_str());
    }
    
    const char* c_str() const{
        return data; 
    }
    
    const int size() const {
        return length;
    }
    
    void append(const String& str) {
       int newlength = length+str.size();
       char* newdata = new char[newlength+1];
       memcpy(newdata, data, length); 
       memcpy(newdata+length, str.data, str.size());
       delete data; 
       data = newdata;
    } 
    
    String operator+(const String& str) {
        String newString;
        newString.length = length + str.size();
        newString.data = new char[newString.length+1];
        strcpy(newString.data, data);
        strcat(newString.data, str.data);
        return newString;
    }
    
    String& operator=(const String& str) {
        length = str.size();      
        delete data; 
        data = new char[length+1];
        strcpy(data, str.data);   
        return *this;
    }
    
    friend ostream& operator<<(ostream &os, String& str) {
        os << str.data;
        return os;
    }

    friend istream& operator>>(istream &is, String& str) {
        int length = is.gcount();     
        char tem[length]; 
        is >> tem;
        str.length = length;
        str.data = new char[length+1];
        strcpy(str.data, tem);
        return is;
    }

public:
    char* data;
    int length; 
};


#endif
