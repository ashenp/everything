#ifndef _EVERYTHING_UNIX_FILEWATCHER
#define _EVERYTHING_UNIX_FILEWATCHER

#include <sys/inotify.h>
#include <assert.h>
#include <map>
#include <string>
#include <vector>
#include <unistd.h>
#include <cstring>

#define EVENT_SIZE (sizeof(inotify_event))

using namespace std;
class FileWatcher{
    
public:
    FileWatcher()
    {
        _inotify_fd = inotify_init();
        assert(_inotify_fd != -1);
    };

    void AddPath(string path, uint32_t mask) {
        int wd = inotify_add_watch(_inotify_fd, path.c_str(), mask);
        assert(wd != -1);
        _wd_path_map.insert(make_pair(wd, path));
        //_wd_mask_map.insert(wd, mask);
    }
    
    void SetBufferLength(uint32_t buffer_length) {
        _buffer_length = buffer_length;
    }
    
    vector<pair<string, pair<uint32_t, string>> >& DoWatch() {
        _res.clear();
        
        char* buffer = (char*)malloc(_buffer_length);
        int read_size = read(_inotify_fd, buffer, _buffer_length);

        while ( read_size == -1 && errno == EINVAL ) {
            _buffer_length *= 2;  
            buffer = (char*)realloc(buffer, _buffer_length);
            read_size = read(_inotify_fd, buffer, _buffer_length);
        }
        
         
        int i = 0;
        int left =  read_size;
        
        while(left >= EVENT_SIZE) {
            struct inotify_event* event = (struct inotify_event*)&buffer[i]; 
            i += EVENT_SIZE;
            left -= EVENT_SIZE;
            i += event->len; 
            left -= event->len;

            string file_name = _wd_path_map[event->wd];
            string e_name = event->name;
            _res.push_back( make_pair(file_name, make_pair(event->mask, e_name)));
        }
        
        return _res; 
    }

private:
    vector<pair<string, pair<uint32_t, string>> > _res;
    int _inotify_fd;
    map<int, string> _wd_path_map;
    int _buffer_length = 64;
    //map<int, string> _wd_mask_map;
};

    
#endif
