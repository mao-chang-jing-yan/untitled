//
// Created by Xiao Shen on 2021/7/15.
//

#include "LNode.h"
#include <iostream>
#include <utility>

using namespace std;

void LNode::push_back(Node *node) {
    if (length == 0) {
        this->data = node;
        *head = node;
        *tail = node;
        length++;
        cout << (this->data->name) << endl;
        return;
    }
    node->front = (*tail);

    (*tail)->next = node;

    tail = &(*tail)->next;
//    *tail = node;
    length++;
    cout << (*tail)->name << endl;
}

void LNode::push_back(const string &&node_name) {
    Node *n = new Node();
    n->name = node_name;
    push_back(n);
}

void LNode::push_front(Node *node) {
    if (length == 0) {
        this->data = node;
        *head = node;
        *tail = node;
        length++;
        cout << (*head)->name << endl;
        return;
    }
    node->next = data;
    data->front = node;
    data = node;
    *head = data;
    length++;
    cout << (*head)->name << endl;
}

void LNode::push_front(const string &&node_name) {
    Node *n = new Node();
    n->name = node_name;
    push_front(n);
}

Node *LNode::pop_back() {
    return *tail;
}

Node *LNode::pop_front() {
    return *head;
}

int LNode::get_length() const {
    return length;
}

Node *LNode::get(int index) {
    Node **this_ = &data;
    if (index >= 0) {
        *this_ = *head;
        for (int i = 0; i < index; ++i) {
            if (nullptr == *this_ || i >= length - 1) {
                break;
            }
            *this_ = (*this_)->next;
        }
    } else {
        *this_ = *tail;
        for (int i = 0; i < -index; ++i) {
            if (nullptr == *this_ || -i >= length - 1) {
                break;
            }
            *this_ = (*this_)->front;
        }
    }
    return *this_;
}

LNode::LNode(const string l[]) {
    for (int i = 0; i < l->length(); ++i) {
        push_back((const string &&) l[i]);
    }
}

Node *LNode::operator[](int index) {
    return get(index);
}


LNode::LNode() = default;



