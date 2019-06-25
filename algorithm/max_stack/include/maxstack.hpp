#ifndef _MAX_STACK
#define _MAX_STACK
#include <stack>

class MaxStack{

public:
    void push(int x) {
        if (max_stack.empty() || getMax() <= x)  max_stack.push(x);
        real_stack.push(x);
    }
    
    void pop() {
        if (real_stack.top() == getMax() )  max_stack.pop();
        return real_stack.pop();
    }
    
    int top() {
        return real_stack.top(); 
    }
    
    int getMax() {
        return max_stack.top(); 
    }
    
private:
    std::stack<int> real_stack;
    std::stack<int> max_stack;
    
};

#endif
