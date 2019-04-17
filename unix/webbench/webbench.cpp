#include "webbench.h"
#include <stdlib.h>
#include <thread>
#include <iostream>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <getopt.h>
#include <netinet/in.h>
#include <time.h>
#include <vector>

int Socket(const char* host, int port);

Bencher::Bencher(char* url_, int c_, int t_) {
    url = url_; 
    clients = c_;
    benchtime = t_;
}

void Bencher::build_request() {
    string uri; 
    string host;
    string str(url);
    if(str.substr(0, 7) == "http://") {
        str = str.substr(7);   
    }
    
    if(str.substr(0, 8) == "https://") {
        str = str.substr(8);   
    }
    
    int pos;
    pos = str.find('/');
    if( pos != -1) {
        host = str.substr(0, pos);
        uri = str.substr(pos);
    }


    int port = 80;
    pos = host.find(':');
    if(pos != -1) {
        port = atoi(host.substr(pos+1).c_str());
        host = host.substr(0, pos);
    }
    

    string request = "";

    request += "GET " + uri + " HTTP/1.1";
    request += "\r\n";
    request += "User-Agent: "; 
    request += "webbench";
    request += "\r\n"; 
    request += "Host: " + host;
    request += "\r\n"; 
    request += "Connection: close\r\n";
    request += "\r\n"; 
    request += "\r\n";
    
    _host = host;
    _port = port;
    _request = request;
}

void Bencher::bench() {
    build_request();
    cout << "bench host:" << _host << endl;
    cout << "bench port:" << _port << endl;
    cout << "bench time:" << benchtime << endl;
    
    vector<thread> v;
    for(int i = 1; i <= clients; i++) {
        thread t(std::bind(&Bencher::benchcore, this));
        v.push_back(std::move(t)); 
    }

    for(vector<thread>::iterator it = v.begin(); it != v.end(); it++) {
       it->join();
    }
    
    cout << "bench done. \r\n";
    cout << "total request:" << success_count + failed_count <<  "\t total success \t" << success_count <<  "\t total failed \t"  << failed_count  << endl;
    cout << "qps:" << success_count / benchtime << endl;
     
    exit(0);
}

void Bencher::benchcore() {
    time_t seconds = time(NULL);
    
    int failed = 0;
    int success = 0;
     
    pthread_t no = pthread_self();
    cout <<  "thread begin\t" << no << "\t starttime:" << seconds << endl;

    while(1) {
        time_t now = time(NULL);
        if(now >= (seconds + this->benchtime) ) {
            cout <<  no  <<" time up ,  current time:"  << now << endl;
            break;
        }
        int fd = Socket(_host.c_str(), _port);
        string result = "";
        if(fd < 0) {
            failed++; 
            cout << "create failed" << endl;
            continue;
        }
        
        int r_len = strlen(_request.c_str());
        if(r_len != write(fd, _request.c_str(), strlen(_request.c_str()))) {
            failed++;
            cout << "send failed" << endl;
            continue;
        }
         
        while(1) {
            char c_recv[1024]; 
            int r_ret = read(fd, c_recv, 1024);
            if(r_ret > 0) {
                result += c_recv;
            } else if(r_ret == 0) {
                success++; 
                break;
            } else {
                failed++;  
                break;
            }
        }
        close(fd);

    }
    success_map[(int)no] =  success;
    success_count   += success;
    failed_map[(int)no]  =  failed;
    failed_count    += failed_count;

}


static string str = "c:t:";

int main(int argc, char* argv[]) {
    int opt;
    int opt_index;
    int c = 1;
    int t = 30; 

    int lopt;
    struct option long_options[] = {
        {"url",     required_argument, NULL,  'u'},
        {0,         0,                 0,  0 }
    };   

    char url[200] = "";
    while( (opt = getopt_long(argc, argv, str.c_str(), long_options, &opt_index)) != -1) {
        switch(opt) {
            case 'c':
            c = atoi(optarg);break;
            case 't':
            t = atoi(optarg);break;
            case 'u':
            strncpy(url, optarg, strlen(optarg)+1);break;
        }
    } 

    cout << "url:" << url << endl;
    cout << "c:" << c << endl;
    cout << "t:" << t << endl;

    if(strlen(url) == 0) {
        cout << "pls input url" << endl; 
        return 1;
    }
    
    Bencher bencher(url, c, t);
    bencher.bench();
    return 0;
}



