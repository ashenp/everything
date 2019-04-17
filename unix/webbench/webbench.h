#ifndef BENCHER_H_
#define BENCHER_H_
#include <string>
#include <map>

using namespace std;
class Bencher{

public:

    Bencher(char* url_, int c_, int t_);

    Bencher() 
        : clients(1) //concurrency
        , benchtime(30)
    {
         
    }

    void bench();

    void benchcore();

    void build_request();


public:

    char* url;

    int clients;

    int benchtime;

    private:
    string _host;

    int    _port;

    string _request;

    int success_count;

    int failed_count;
    
    map<int, int> success_map;

    map<int, int> failed_map;

};

#endif

