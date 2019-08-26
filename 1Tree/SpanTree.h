//
// Created by 陈姝宇 on 2019/8/26.
//

#ifndef BINARYSEARCHTREE_SPANTREE_H
#define BINARYSEARCHTREE_SPANTREE_H

#include "BinaryTree.h"

struct SpanNode : TreeNode {
    // 父节点，便于旋转
    SpanNode * parent;
    int height;
    SpanNode * left,* right;
    explicit SpanNode(int val) : TreeNode(val) {
        height = 0;
        parent = nullptr;
    };
};

class SpanTree : public BinaryTree {

};


#endif //BINARYSEARCHTREE_SPANTREE_H
