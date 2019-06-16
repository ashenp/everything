#ifndef _LRU_CACHE_HPP
#define _LUR_CACHE_HPP

#include <list>
#include <unordered_map>
#include <mutex>

template<typename key_t, typename value_t>
class lru_cache{
public:
    typedef typename std::pair<key_t, value_t> key_value_pair_t;
    typedef typename std::list<key_value_pair_t>::iterator list_iterator_t;
    
    
    lru_cache(size_t max_size) 
        :_max_size(max_size)
    {

    }
    
    void put(const key_t& key, const value_t& value) {

        _mutex.lock();
        auto it = _cache_items_map.find(key);

        if(it != _cache_items_map.end() ) {
            *(it->second) = make_pair(key, value);
            _cache_items_map.erase(it); 
        } 

        _cache_items_list.push_front(key_value_pair_t(key, value));  
        _cache_items_map[key] = _cache_items_list.begin();
        
        if(_cache_items_map.size() > _max_size) {
            auto last = _cache_items_list.end(); 
            last--;
            _cache_items_map.erase(last->first);
            _cache_items_list.pop_back();
        } 
        _mutex.unlock();
    }
    
    const value_t& get(const key_t& key) {
        _mutex.lock();
        auto it = _cache_items_map.find(key);
        if(it == _cache_items_map.end()) {
            throw std::range_error("There is no such key in cache");
        } else  {
            _cache_items_list.splice(_cache_items_list.begin(), _cache_items_list, it->second);
            return it->second->second;
        }
        _mutex.unlock();
    }
    
    size_t size() const {
        return _cache_items_map.size(); 
    }
    
private:
    
    std::mutex _mutex;
    std::list<key_value_pair_t> _cache_items_list;
    std::unordered_map<key_t, list_iterator_t> _cache_items_map;
    size_t _max_size;
};

#endif
