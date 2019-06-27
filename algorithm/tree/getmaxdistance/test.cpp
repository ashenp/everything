#include "include/treenode.hpp"
#include <iostream>
#include <algorithm>
#include <cstddef>

int getHeight(TreeNode* root) {
    if(root == NULL) {
        return 0; 
    }
    
    int left_height = getHeight(root->lchild);
    int right_height = getHeight(root->rchild);

    return std::max(left_height, right_height) + 1;
}

int getMaxDistance(TreeNode* root) {
    if(root == NULL) {
        return 0; 
    }
    int max_dis = std::max(std::max(getHeight(root->lchild) + getHeight(root->rchild), getMaxDistance(root->lchild) ),
                            getMaxDistance(root->rchild)
    );
    return max_dis;
}


int main(int argc, char** argv) {
    TreeNode* node_40 = new TreeNode(40);
    TreeNode* node_20 = new TreeNode(20);
    TreeNode* node_5 = new TreeNode(5);
    TreeNode* node_1 = new TreeNode(1);
    TreeNode* node_80 = new TreeNode(80);
    TreeNode* node_90 = new TreeNode(90);
    TreeNode* node_70 = new TreeNode(70);
    TreeNode* node_100 = new TreeNode(100);
    TreeNode* node_110 = new TreeNode(110);
    node_40->lchild = node_20; 
    node_40->rchild = node_80;
    node_80->lchild = node_5;
    node_80->rchild = node_90;
    node_90->rchild = node_100;
    node_100->rchild = node_110;
    node_5->lchild = node_1;
    node_1->lchild = node_70;

    
    std::cout << "max distance::" << getMaxDistance(node_40) << std::endl;;
    return 0;
    
}
