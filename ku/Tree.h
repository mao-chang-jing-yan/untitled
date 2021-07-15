//
// Created by Xiao Shen on 2021/7/13.
//

#ifndef UNTITLED_TREE_H
#define UNTITLED_TREE_H

#include <iostream>
#include "string"

using namespace std;

typedef struct TNode {
    string name;
    int deep;
    TNode *left;
    TNode *right;
} tNode;

class Tree {
private:
    TNode *root;

public:
    Tree();

    explicit Tree(string &&s);

    tNode *getRoot();

    void setRoot(const TNode *r);

    void setRoot(const string &&s);

    void add(TNode *r, const TNode *left, const TNode *right);

    void add(TNode *r, const string &&left, const string &&right);

    TNode *newTNode(string &&s);

    void pPrint();

    void mPrint();

    void nPrint();

    void pPrint_(const TNode *t);

    void mPrint_(const TNode *t);

    void nPrint_(const TNode *t);


};


#endif //UNTITLED_TREE_H
