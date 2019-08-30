#ifndef _EVERYTHING_TREE_NODE_HPP
#define _EVERYTHING_TREE_NODE_HPP
#include <vector>
#include <deque>
#include <cstddef>

template <typename T>
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
};

template <typename T>
void printTree(TreeNode<T>* root) { 
    std::deque<TreeNode<T>*> q_treenode;
    q_treenode.push_back(root);
    while(!q_treenode.empty()) {
        TreeNode<T>* t = q_treenode.front();    
        q_treenode.pop_front();    
        if(t->left != NULL) {
            q_treenode.push_back(t->left); 
        } 
        if(t->right != NULL) {
            q_treenode.push_back(t->right); 
        }
    }
}


#endif

