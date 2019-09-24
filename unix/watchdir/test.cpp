#include <iostream>

#include "include/filewatcher.hpp"


using namespace std;

int main(int argc, char* argv[]) {
    string dir_name = "/home/map/test_dir";   

    FileWatcher* watcher  = new FileWatcher();
    watcher->AddPath(dir_name, IN_CREATE);
    while(1) {
        auto v = watcher->DoWatch(); 
        cout << "event happens" << endl; 
    }
    
    return 0;
}
