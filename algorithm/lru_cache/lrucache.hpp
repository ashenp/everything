#ifndef _LRU_CACHE
#define _LRU_CACHE
#include <list>
#include <map>
#include <cstddef>
#include <iostream>

template<typename key_t, typename value_t>

class LRUCache{
public:
typedef typename std::pair<key_t, value_t> pair_key_value;
typedef typename std::list<pair_key_value>::iterator it;

LRUCache(int max_size) : _max_size(max_size) {

}

void put(key_t k, value_t v) {

    auto jt= _map_cache.find(k);
    if (jt != _map_cache.end() ) {
        _list_cache.erase(jt->second); 
        _map_cache.erase(jt);
    }
    
    _list_cache.push_front(make_pair(k, v));
    _map_cache.insert(make_pair(k, _list_cache.begin()) );
    
    if(_map_cache.size() > _max_size) {
        auto last = _list_cache.end();  
        last--;
        _map_cache.erase(_map_cache.find(last->first));
        _list_cache.pop_back();
    }
}

value_t get(key_t k) {
    auto jt = _map_cache.find(k); 
    if(jt == _map_cache.end() ) {
        throw std::range_error("no such key");
    } else {
        _list_cache.splice(_list_cache.begin(), _list_cache, jt->second);    
        return jt->second->second;
    } 
}

void output() {
    std::cout << "current list: ";
    for(auto i : _list_cache) {
        std::cout << i.first << ":" << i.second << " -> "; 
    }
    std::cout << std::endl;
    std::cout << "current list size :" << _list_cache.size() << std::endl;
    std::cout << "current map size :" << _map_cache.size() << std::endl;
}
    
private:
    std::list<pair_key_value> _list_cache;
    std::map<key_t, it> _map_cache;
    int _max_size;
};

#endif
