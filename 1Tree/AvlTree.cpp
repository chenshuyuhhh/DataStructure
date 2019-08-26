//
// Created by 陈姝宇 on 2019/8/26.
//

#include "AvlTree.h"


AvlTree::~AvlTree() {
    delete rootNode;
}

AvlTree::AvlTree(AvlNode *&avlNode) {
    this->rootNode = avlNode;
}

void AvlTree::insertBST(AvlNode *&node, int key) {
    if (node == nullptr) {
        node = (struct AvlNode *) malloc(sizeof(struct AvlNode));
        if (node) {
            node->val = key;
            node->left = nullptr;
            node->right = nullptr;
            node->height = 0;
        } else {
            std::cout << "内存分配失败" << std::endl;
        }
    } else {
        if (key < node->val) {
            // 插入左子树
            insertBST(node->left, key);
            // 判断是否破坏平衡性
            if (NodeHeight(node->left) - NodeHeight(node->right) == 2)
                LeftBalance(node);
        } else if (key > node->val) {
            // 插入右子树
            insertBST(node->right, key);
            if (NodeHeight(node->right) - NodeHeight(node->left) == 2)
                RightBalance(node);
        }
        // 更新根节点
        caculateH(node);
    }
}

void AvlTree::deleteAvl(AvlNode *&node, int key) {
    if (node == nullptr)
        return;
    if (key < node->val) {
        deleteAvl(node->left, key);
        if (NodeHeight(node->right) - NodeHeight(node->left) == 2)
            RightBalance(node);
    } else if (key > node->val) {
        deleteAvl(node->right, key);
        if (NodeHeight(node->left) - NodeHeight(node->right) == 2)
            LeftBalance(node);
    } else {
        // 找到待删结点
        if (node->left == nullptr) {
            // 左子树为空
            AvlNode *temp = node;
            node = node->right;
            // 释放内存
            free(temp);
        } else if (node->right == nullptr) {
            AvlNode *temp = node;
            node = node->left;
            free(temp);
        } else {
            // 左右子树都不为空
            // 用左子树中的最大值代替
            // 左子树的最大值应为最右的结点
            AvlNode *beforenode = node->left;
            while (beforenode->right) beforenode = beforenode->right;
            node->val = beforenode->val;
            // 递归删除该结点
            deleteAvl(node->left,beforenode->val);
        }
    }
    // 更新结点高度
    if(node) caculateH(node);
}


void AvlTree::deleteTree(int key) {
    deleteAvl(rootNode, key);
}

void displayNodes(AvlNode *node) {
    if (node != nullptr) {
        displayNodes(node->left);
        std::cout << node->val << " ";
        displayNodes(node->right);
    }
}

void AvlTree::displayNode() {
    displayNodes(rootNode);
}

/**
 * LL型，往右旋转，处理左孩子的左子树的比右子树高
 * @param node
 */
void AvlTree::rotateRight(AvlNode *&node) {
    // 先保存结点的左子树
    AvlNode *leftchild = node->left;
    // 将原结点的左孩子的右孩子作为原结点的左子树
    node->left = leftchild->right;
    // 节点的左孩子的右子树转换为原结点
    leftchild->right = node;
    // LL型右旋完成
    // 更新树的深度，原结点和原结点的左子树深度发生变化
    caculateH(node);
    caculateH(leftchild);
    node = leftchild;
}

/**
 * RR型，往左旋转，处理右孩子的右子树比左子树高
 * @param node
 */
void AvlTree::rotateLeft(AvlNode *&node) {
    // 先保存结点的右孩子
    AvlNode *rightchild = node->right;
    // 将原结点的右孩子的左孩子作为原结点的右子树
    node->right = rightchild->left;
    // 节点的左孩子的右子树转换为原结点
    rightchild->left = node;
    // RR型左旋完成
    // 更新树的深度，原结点和原结点的右子树深度发生变化
    caculateH(node);
    caculateH(rightchild);
    node = rightchild;
}

/**
 * 先左旋再右旋，处理左孩子的右子树比左子树高的情况
 * @param node
 */
void AvlTree::rotateLeftRight(AvlNode *&node) {
    rotateLeft(node->left);
    rotateRight(node);
}

/**
 * 先右旋再左旋，处理右孩子的左子树比右子树高的情况
 * @param node
 */
void AvlTree::rotateRightLeft(AvlNode *&node) {
    rotateRight(node->right);
    rotateLeft(node);
}

/**
 * 右平衡，处理右子树不平衡
 * @param node
 */
void AvlTree::RightBalance(AvlNode *&node) {
    AvlNode *temp = node->right;
    if (NodeHeight(temp->right) - NodeHeight(temp->left) == -1)
        // 左子树比右子树高
        rotateRightLeft(node);
    else
        rotateLeft(node);
}

void AvlTree::LeftBalance(AvlNode *&node) {
    // 获得节点的左孩子
    AvlNode *temp = node->left;
    // 判断失去平衡的是左子树还是右子树
    if (NodeHeight(temp->left) - NodeHeight(temp->right) == -1)
        // 右子树高于左子树，先左旋再右旋
        rotateLeftRight(node);
    else
        rotateRight(node);
}

int AvlTree::NodeHeight(AvlNode *&node) {
    return node == nullptr ? -1 : node->height;
}

int AvlTree::Max(int p1, int p2) {
    return p1 < p2 ? p2 : p1;
}

/**
 * 计算树的高度
 * @param node
 */
void AvlTree::caculateH(AvlNode *&node) {
    node->height = Max(NodeHeight(node->left), NodeHeight(node->right)) + 1;
}

void AvlTree::insertBST(int key) {
    insertBST(rootNode, key);
}

void AvlTree::setRootNode(AvlNode *&rootNode) {
    this->rootNode = rootNode;
}

AvlNode *AvlTree::getRootNode() {
    return rootNode;
}
