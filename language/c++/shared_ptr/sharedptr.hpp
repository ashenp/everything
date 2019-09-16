#ifndef _EVERYTHING_LANGUAGE_CPLUSPLUS_SHARED_PTR
#define _EVERYTHING_LANGUAGE_CPLUSPLUS_SHARED_PTR
#include <iostream>


template <typename T>
class SharedPtr{ 
private:
    T* _ptr;
    size_t* _count;
public:
    SharedPtr(T* ptr = nullptr) : 
    _ptr(ptr)
    {
        if (_ptr) {
            _count = new size_t(1);      
        } else {
            _count = new size_t(0);
        }
    }
    
    SharedPtr(const SharedPtr& ptr) {
        if (this != &ptr) {
            this->_ptr = ptr._ptr;  
            this->_count = ptr._count;
            ++(*this->_count);
        }
    }
    
    SharedPtr& operator=(const SharedPtr& ptr) {
        if (this->_ptr = ptr._ptr) {
            return this; 
        }
        
        if (this->_ptr) {
            --(*this->_count);
            if ( (*this->_count) == 0 ) {
                delete _ptr; 
                delete _count;
            }
        }
        
        this->_ptr = ptr._ptr;
        this->_count = ptr._count;
        ++(*this->_count);

        return *this;
    }
    
    
    
    T* operator* () {
        assert(this->_ptr == nullptr); 
        return *(this->_ptr);
    }
    
    T* operator->() {
        assert(this->_ptr == nullptr); 
        return this->_ptr;
    }
    
    ~SharedPtr() {
        --(*this->_count);
        if(*this->_count == 0) {
            delete this->_ptr; 
            delete this->_count;
        }
        
    }



};

#endif
