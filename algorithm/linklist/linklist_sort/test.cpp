#include <iostream>
#include "include/listnode.h"



ListNode* toutiao_listnode(ListNode* head) {
    ListNode* odd_head = head;
    ListNode* even_head = head->next; 
    ListNode* odd_node = odd_head;
    ListNode* even_node = even_head;
    while(even_node && even_node->next) {
        odd_node->next = odd_node->next->next; 
        odd_node = odd_node->next;
        even_node->next = even_node->next->next;
        even_node = even_node->next;
    }
     
     
    ListNode* even_head_new = reverseList(even_head);  
    ListNode* res = mergeTwoLists(odd_head, even_head_new); 
    
    return res;
}


int main(int argc, char** argv) {

    ListNode* originList = initList({1, 8, 3, 6, 5, 4, 7});
    ListNode* res = toutiao_listnode(originList);
    outputList(res);
    return 0;

}
