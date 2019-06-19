#include <iostream>
#include "include/listnode.h"
#include <vector>

void reverse(ListNode* head, std::vector<int>& res) {
    if(head && head->next) {
        reverse(head->next, res);
    }
    res.push_back(head->val);
}

std::vector<int> printListFromTailToHead(ListNode* head) {
        std::vector<int> res;
        if(head == NULL) {
            return res; 
        }
        reverse(head, res);
        return res;
}
    


void printVector(const std::vector<int>& vec) {
    for(auto x : vec) {
        std::cout << x << ",";
    }
    std::cout << std::endl;
}

int main(int argc, char** argv) {
    ListNode* originList = initList({});
    std::vector<int> res = printListFromTailToHead(originList);
    printVector(res);
    
    return 0;

}
