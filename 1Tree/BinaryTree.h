//
// Created by 陈姝宇 on 2019/8/26.
//

#ifndef BINARYSEARCHTREE_BINARYTREE_H
#define BINARYSEARCHTREE_BINARYTREE_H
#include "iostream"

//-------- binary search tree -------//
/**
 * 结点
 */
struct TreeNode {
    int val;
    TreeNode *left, *right;

    explicit TreeNode(int val) : left(nullptr), right(nullptr), val(val) {}
};

class BinaryTree {
public:

    BinaryTree();

    ~BinaryTree();

    virtual void insertBST(int key);

    virtual void displayNode();

    virtual void deleteTree(int key);

};


#endif //BINARYSEARCHTREE_BINARYTREE_H
