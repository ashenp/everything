#ifndef _EVERYTHING_TREE_NODE_HPP
#define _EVERYTHING_TREE_NODE_HPP
#include <vector>
#include <deque>
#include <cstddef>

struct TreeNode{
    int val;
    TreeNode* lchild;
    TreeNode* rchild;
    TreeNode(int x) : val(x), lchild(NULL), rchild(NULL) {}
};

void printTree(TreeNode* root) { 
    std::deque<TreeNode*> q_treenode;
    q_treenode.push_back(root);
    while(!q_treenode.empty()) {
        TreeNode* t = q_treenode.front();    
        q_treenode.pop_front();    
        if(t->lchild != NULL) {
            q_treenode.push_back(t->lchild); 
        } 
        if(t->rchild != NULL) {
            q_treenode.push_back(t->rchild); 
        }
    }
}


#endif

