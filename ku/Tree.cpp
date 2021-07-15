//
// Created by Xiao Shen on 2021/7/13.
//

#include <iostream>
#include <string>
#include "Tree.h"

using namespace std;


Tree::Tree(string &&s) {
    this->root = new tNode();
    this->root->name = s;
}

Tree::Tree() {
    this->root = new tNode();
}
void Tree::setRoot(const TNode *r) {
    this->root = const_cast<TNode *>(r);
}
void Tree::setRoot(const string &&s) {
    this->root = new tNode();
    this->root->name = s;
}
tNode *Tree::getRoot() {
    return this->root;
}
void Tree::add(TNode *r, const TNode *left, const TNode *right) {
    r->left = const_cast<TNode *>(left);
    r->right = const_cast<TNode *>(right);
}
void Tree::add(TNode *r, const string &&left, const string &&right) {
    r->left = newTNode(const_cast<string &&>(left));
    r->right = newTNode(const_cast<string &&>(right));
}
TNode *Tree::newTNode(string &&s) {
    auto n = new TNode();
    n->name = s;
    return n;
}

void Tree::pPrint_(const TNode *t) {
    if (t == nullptr) {
        return;
    }
    cout << t->name << " ";
    pPrint_(t->left);
    pPrint_(t->right);
}

void Tree::mPrint_(const TNode *t) {
    if (t == nullptr) {
        return;
    }
    mPrint_(t->left);
    cout << t->name << " ";
    mPrint_(t->right);
}

void Tree::nPrint_(const TNode *t) {
    if (t == nullptr) {
        return;
    }
    nPrint_(t->left);
    nPrint_(t->right);
    cout << t->name << " ";
}

void Tree::pPrint() {
    pPrint_(this->root);
    cout << endl;
}

void Tree::mPrint() {
    mPrint_(this->root);
    cout << endl;
}

void Tree::nPrint() {
    nPrint_(this->root);
    cout << endl;
}












