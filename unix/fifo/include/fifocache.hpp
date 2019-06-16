#ifndef _FIFO_CACHE_HPP
#define _FIFO_CACHE_HPP

#include <list>
#include <unordered_map>
#include <mutex>

template<typename key_t, typename value_t>
class fifo_cache{
public:
    typedef typename std::pair<key_t, value_t> key_value_pair_t;
    typedef typename std::list<key_value_pair_t>::iterator list_iterator_t;
    
    
    fifo_cache(size_t max_size) 
        :_max_size(max_size)
    {

    }
    
    void put(const key_t& key, const value_t& value) {

        _mutex.lock();
        auto it = _cache_items_map.find(key);
        //already in cache, nothing to do
        if(it != _cache_items_map.end()) {
            *(it->second) = make_pair(key, value);
            _mutex.unlock();
            return;
        }
        
        if(_cache_items_map.size() >= _max_size) {
            auto last = _cache_items_list.end();
            last--;
            auto last_item_it  = _cache_items_map.find(last->first);
            _cache_items_map.erase(last_item_it);  
            _cache_items_list.pop_back();
        }
        
        _cache_items_list.push_front(make_pair(key, value));
        _cache_items_map[key] = _cache_items_list.begin();
        _mutex.unlock();
    }
    
    const value_t& get(const key_t& key) {
        _mutex.lock();
        auto it = _cache_items_map.find(key);
        if(it == _cache_items_map.end()) {
            throw std::range_error("There is no such key in cache");
        } else  {
            return it->second->second;
        }
        _mutex.unlock();
    }
    
    void output() {
        for(auto i = _cache_items_list.begin(); i !=  _cache_items_list.end(); i++) {
            std::cout << "[" << (*i).first << ":" << (*i).second << "]";
        }
        std::cout << std::endl;
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
