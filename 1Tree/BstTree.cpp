//
// Created by 陈姝宇 on 2019/8/26.
//
#include "BstTree.h"

BstTree::BstTree(TreeNode *rootNode) : BinaryTree() {
    this->rootNode = rootNode;
}

BstTree::~BstTree() {
    delete rootNode;
}

void BstTree::insertBST(int key) {
    if (rootNode == nullptr) {
        rootNode = new TreeNode(key);
    } else {
        TreeNode *temp = rootNode;
        TreeNode *parent = nullptr;
        while (temp) {
            parent = temp;
            // 比较待插入的值和根结点大小
            if (key == temp->val) {
                //return nullptr;
            } else if (key < temp->val) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        // 只对大于或者小于情况插入，等于不插入，因为bst树没有重复结点
        if (key < parent->val)
            parent->left = new TreeNode(key);
        else if (key > parent->val)
            parent->right = new TreeNode(key);
    }
}

/**
 * 解决当被删除结点左右子树都不为空的时候如何删除
 * @param node
 */
void specialDeleteNode(TreeNode *&node) {
    // 寻找后继结点，后继结点必然是原结点的右子树的最左子结点
    // 后继结点
    TreeNode *nextNode = node->right;
    // 后继结点的父节点
    TreeNode *parentOfNext = nullptr;
    while (nextNode->left) {
        parentOfNext = nextNode;
        nextNode = nextNode->left;
    }
    // 交换原结点和后继结点
    // 修改结点值
    node->val = nextNode->val;
    if (parentOfNext == nullptr) {
        node->right = nextNode->right;
    } else {
        parentOfNext->left = nextNode->right;
    }
    // 删除原结点
    delete nextNode;
}

/**
 * 删除结点，如果是空的，直接返回。
 * @param node
 * @param key
 * @return
 */
void BstTree::deleteTree(int key) {
    if (rootNode != nullptr) {
        // 找到结点的位置和父结点
        TreeNode *temp = rootNode;
        TreeNode *parent = nullptr;
        while (temp) {
            // 比较待插入的值和根结点大小
            if (key == temp->val) {
                break;
            } else if (key < temp->val) {
                parent = temp;
                temp = temp->left;
            } else {
                parent = temp;
                temp = temp->right;
            }
        }
        if (parent == nullptr) {
            // 删除结点为根结点的情况
            if (temp->left == nullptr)
                // 左子树为空
                rootNode = temp->right;
            else if (temp->right == nullptr)
                // 右子树为空
                rootNode = temp->left;
            else {
                // 左右子树均不为空
                specialDeleteNode(rootNode);
            }
        } else if (temp != nullptr) {
            // 删除结点不为根结点
            if (temp->left == nullptr) {
                // 判断父结点的左孩子还是右孩子为待删除结点
                if ((parent->left != nullptr && parent->left->val != key) || parent->left == nullptr)
                    // 左孩子为空或者左孩子不为空但是左孩子的值不等于待删结点的值，则说明父结点的右孩子为待删结点
                    parent->right = temp->right;
                else
                    parent->left = temp->right;
            } else if (temp->right == nullptr) {
                if ((parent->left != nullptr && parent->left->val != key) || parent->left == nullptr)
                    parent->right = temp->left;
                else
                    parent->left = temp->left;
            } else {
                specialDeleteNode(temp);
            }
        } else {
            // 不存在待删除的结点
            std::cout << "no exist " << key << std::endl;
        }
    } else
        // 结点为空
        std::cout << "node not exist" << std::endl;
}

void displayNodes(TreeNode *node) {
    if (node != nullptr) {
        displayNodes(node->left);
        std::cout << node->val << " ";
        displayNodes(node->right);
    }
}

/**
 * 中序遍历打印结点
 */
void BstTree::displayNode() {
    displayNodes(rootNode);
}

void BstTree::setRootNode(TreeNode *&rootNode) {
    this->rootNode = rootNode;
}

TreeNode *BstTree::getRootNode() {
    return this->rootNode;
}