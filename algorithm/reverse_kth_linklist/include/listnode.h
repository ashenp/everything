#ifndef _LIST_NODE_
#define _LIST_NODE_

#include <vector>
#include <iostream>

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


void outputList(ListNode* head) {
    while(head && head->next) {
        std::cout << head->val << "<<";
        head = head->next;
    }
    std::cout << head->val << std::endl;
}

ListNode* initList(const std::vector<int>& vec) {

    ListNode* head = new ListNode(0);
    ListNode* cur  = head;
    for(auto i : vec) {
        cur->next = new ListNode(i);    
        cur = cur->next;
    }
    return head->next;
     
}

ListNode* reverseList(ListNode* head) {
    ListNode* cur = NULL;  
    while(head) {
        ListNode* next = head->next; 
        head->next = cur;
        cur = head;
        head = next;   
    }
    return cur;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* l = new ListNode(0); 
    ListNode* cur = l;
    
    while(l1 || l2) {
        if(l1 == NULL) {
            cur->next = l2;
            break;
        }
        if(l2 == NULL) {
            cur->next = l1;
            break;
        }
        if(l1->val > l2->val) {
            cur->next = l2;
            cur = cur->next; 
            l2 = l2->next;
        } else {
            cur->next = l1;
            cur = cur->next; 
            l1 = l1->next;
        }
    }
    return l->next;
}

#endif
