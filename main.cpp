#include <iostream>
#include <cstdlib>
#include <ctime>
#include "1Tree/BstTree.h"
#include "1Tree/AvlTree.h"

using namespace std;

void bstTest();

void avlTest();

void spanTest();

int main() {
    bstTest();
    avlTest();
   // spanTest();

    return 0;
}

void bstTest() {
    TreeNode *node = nullptr;
    auto *bstTree = new BstTree(node);
    int number[7000];
    for (int &i : number) {
        srand(static_cast<unsigned int>((int) time(nullptr)));
        i = static_cast<int>(random() % 800000000);
        bstTree->insertBST(i);
    }
    bstTree->displayNode();
    for (int &i : number) {
        bstTree->displayNode();
        cout << endl;
        bstTree->deleteTree(i);
    }
}

void avlTest(){
    AvlNode *node = nullptr;
    auto *avlTree = new AvlTree(node);
    int number[10000];
    for (int &i : number) {
        srand(static_cast<unsigned int>((int) time(nullptr)));
        i = static_cast<int>(random() % 80000000);
        avlTree->insertBST(i);
    }
    for (int &i : number) {
        avlTree->displayNode();
        cout << endl;
        avlTree->deleteTree(i);
    }
}