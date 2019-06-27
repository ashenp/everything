#include <iostream>
#include <vector>
#include "include/treenode.hpp"

TreeNode* initBiTree(const std::vector<int> arr) {
    std::vector<TreeNode*> ptree;
    for(auto i : arr) {
        ptree.push_back(new TreeNode(i)); 
    }
    
    int n = arr.size();
    
    for(int i = 0; i < n/2-1; i++) {
        if(2*i + 1 < n-1) {
            ptree[i]->lchild = ptree[2*i+1];
        }  
        if(2*i + 2 < n-2) {
            ptree[i]->rchild = ptree[2*i+2]; 
        }
    }
    return ptree[0];
}



int main(int argc, char** argv) {

    TreeNode* root = initBiTree({1, 2, 3, 4, 5});
    
    printTree(root);
    
    return 0;
    
}
