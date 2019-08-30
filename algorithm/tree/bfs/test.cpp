#include "include/treenode.hpp"
#include <iostream>
#include <algorithm>
#include <cstddef>
#include <deque>

using namespace std;

template <typename T>
vector<T> bfs(TreeNode<T>* root) {   
    vector<T> res;
    deque<TreeNode<T>*> n_deque;
    n_deque.push_front(root);
    while (!n_deque.empty()) {
        TreeNode<T>* tmp = n_deque.front(); 
        n_deque.pop_front();
        res.push_back(tmp->val); 
        if (tmp->left)  n_deque.push_back(tmp->left);
        if (tmp->right) n_deque.push_back(tmp->right);
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
    
    auto res = bfs(a);
    cout << "dfs result:";
    for (auto i : res) {
        cout << i;
    }
    cout << endl; 
    return 0;
    
}
