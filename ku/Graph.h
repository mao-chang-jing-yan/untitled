//
// Created by Xiao Shen on 2021/7/13.
//

#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H

#include <iostream>
#include <string>

using namespace std;
struct Edge;
struct GNode {
    string name;
    GNode *gNodeList;
    Edge *edgeList;
};

struct Edge {
    GNode *pNode;
    GNode *nNode;
    int direct;
};

class Graph {
private:
    GNode *nodeList;
    Edge *edgeList;



};


#endif //UNTITLED_GRAPH_H
