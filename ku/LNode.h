//
// Created by Xiao Shen on 2021/7/15.
//

#ifndef UNTITLED_LNODE_H
#define UNTITLED_LNODE_H

#include <iostream>
#include <string>

using namespace std;
struct Node {
    string name;
    Node *next;
    Node *front;
};

class LNode {
private:
    Node *data{};
    Node **head = &data;
    Node **tail = &data;
    int length{};
public:
    LNode();
    explicit LNode(const string l[]);
    int get_length() const;
    void push_back(Node *node);

    void push_back(const string &&node_name);

    void push_front(Node *node);

    void push_front(const string &&node_name);

    Node *pop_back();

    Node *pop_front();

    Node *get(int index);

    Node* operator[](int index);
};


#endif //UNTITLED_LNODE_H
