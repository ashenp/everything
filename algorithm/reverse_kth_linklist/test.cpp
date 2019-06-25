#include <iostream>
#include <algorithm>
#include <vector>
#include "include/listnode.h"

using namespace std;

ListNode* reverse_kgroup_linklist(ListNode* head, int k){
    vector<int> v_int;
    while(head) {
        v_int.push_back(head->val); 
        head = head->next;
    }
    
    int g_num = v_int.size()/k;
    int i = 0;
    while(i < g_num) {
        int start = i*k;
        int end = (i+1)*k - 1;
        while(start < end) {
            swap(v_int[start], v_int[end]); 
            start++;
            end--;
        }  
        i++;
    }
    
    ListNode* new_list = initList(v_int);
    return new_list;
}


int main(int argc, char** argv) {
    ListNode* head = initList({1,2,3,4,5,6});
    ListNode* after = reverse_kgroup_linklist(head, 4);
    outputList(after);
    return 0;
}
