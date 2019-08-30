#include "include/treenode.hpp"
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <stack>

using namespace std;

template <typename T>
vector<T> dfs(TreeNode<T>* root) {   
    vector<T> res;
    stack<TreeNode<T>*> n_stack;  
    n_stack.push(root);
    while (!n_stack.empty()) {
        TreeNode<T>* tmp = n_stack.top(); 
        n_stack.pop();
        res.push_back(tmp->val); 
        if (tmp->right) n_stack.push(tmp->right);
        if (tmp->left)  n_stack.push(tmp->left);
    }
    return res;
}

int main(int argc, char** argv) {
    TreeNode<char> *a = new TreeNode<char>('a');
    TreeNode<char> *b = new TreeNode<char>('b');
    TreeNode<char> *c = new TreeNode<char>('c');
    TreeNode<char> *d = new TreeNode<char>('d');
    TreeNode<char> *e = new TreeNode<char>('e');
    TreeNode<char> *f = new TreeNode<char>('f');
    TreeNode<char> *g = new TreeNode<char>('g');
    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    
    auto res = dfs(a);
    cout << "dfs result:";
    for (auto i : res) {
        cout << i;
    }
    cout << endl; 
    return 0;
    
}
