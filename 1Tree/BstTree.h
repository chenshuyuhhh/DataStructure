//
// Created by 陈姝宇 on 2019/8/26.
//

#ifndef BINARYSEARCHTREE_BSTTREE_H
#define BINARYSEARCHTREE_BSTTREE_H

#include "BinaryTree.h"

class BstTree : public BinaryTree {
public:
    explicit BstTree(TreeNode *treeNode);

    ~BstTree();

    void setRootNode(TreeNode *&rootNode);

    TreeNode *getRootNode();

    void displayNode() override;

    void insertBST(int key) override;

    void deleteTree(int key) override;

private:
    TreeNode *rootNode;
};


#endif //BINARYSEARCHTREE_BSTTREE_H
