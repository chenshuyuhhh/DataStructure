//
// Created by 陈姝宇 on 2019/8/26.
//

#ifndef BINARYSEARCHTREE_AVLTREE_H
#define BINARYSEARCHTREE_AVLTREE_H

#include "BinaryTree.h"

struct AvlNode : TreeNode {
    int height;
    AvlNode * left,* right;
    explicit AvlNode(int val) : TreeNode(val) { height = 0; };
};

class AvlTree : public BinaryTree {
public:
    ~AvlTree();

    explicit AvlTree(AvlNode *&avlNode);

    void insertBST(int key) override;


    void insertBST(AvlNode *&node,int key);

    /**
     * 删除结点，如果是空的，直接返回。
     * @param key
     */
    void deleteTree(int key) override;

    void deleteAvl(AvlNode * &node,int key);

    void displayNode() override;

    void setRootNode(AvlNode *&rootNode);

    AvlNode *getRootNode();

protected:
    // 左旋
    void rotateLeft(AvlNode * &node);

    // 右旋
    void rotateRight(AvlNode * &node);

    // 左旋优选
    void rotateLeftRight(AvlNode * &node);

    void rotateRightLeft(AvlNode * &node);

    void RightBalance(AvlNode * &node);

    void LeftBalance(AvlNode * &node);

    int NodeHeight(AvlNode * &node);

private:
    AvlNode *rootNode;

    void caculateH(AvlNode * & node);

    int Max(int p1,int p2);
};


#endif //BINARYSEARCHTREE_AVLTREE_H
