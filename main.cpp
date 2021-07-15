#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <map>
#include "ku/Point.h"
#include "ku/Tree.h"
#include "ku/jz.h"
#include "ku/LNode.h"

using namespace std;

double sqrt(double x, double num);

void sqrtTest();

void treeTest();

void groupTest();

int relation(int **rela);

void jzTest();

void nodeTest();



int main() {
//    sqrtTest();
//    treeTest();
//    groupTest();
//    jzTest();
    nodeTest();
    return 0;
}

void nodeTest() {

    map<int, string> mapStudent;
    mapStudent[1] = "12";

    LNode l;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 1; ++j) {
            l.push_back(to_string(i) + "   " + to_string(j));
        }
    }

    pair<int, string> s = pair<int, string>();


    cout << endl;
    cout << " 1 =  " << l[0]->name << endl;
//    l.get(3);

}


void jzTest() {
    double d[100][600] = {
            {1, 2, 3, 4, 5,},
            {1, 2, 3, 4, 5,},
            {1, 2, 3, 4, 5,},
    };
    jz *j = new jz((double *) (d), 100, 600);

    j->Print();
    j->T()->Print();

//    jz *j1 = new jz((double *) (d), 1000, 6000);
//    *j = *j + *j1;


}

void groupTest() {
    int a[10][10] = {
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 1, 0, 0, 0},
            {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    };
}

int relation(int **rela) {
    cout << *rela << endl;
//    for (int i = 0; i < 10; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            if (i == j) {
//                a[i][j] = 1;
//            }
//            cout << a[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    for (int i = 0; i < 10; ++i) {
//        for (int j = 0; j < 10; ++j) {
//            cout << b[i][j] << " ";
//        }
//        cout << endl;
//    }
    return 0;
}


void treeTest() {
    Tree t("root");
    list<TNode *> a;
    for (int i = 0; i < 10; ++i) {
        a.push_back(t.newTNode("i" + to_string(i)));
    }
    cout << a.size() << endl;

    t.add(t.getRoot(), a.back(), a.back());
    auto b = a.back();
    a.pop_back();
    t.add(b, a.back(), a.back());

    b = a.back();
    a.pop_back();
    t.add(b, nullptr, a.back());

    b = a.back();
    a.pop_back();
    t.add(b, nullptr, a.back());


    t.pPrint();
    t.mPrint();
    t.nPrint();
}

void sqrtTest() {
    Point p1 = Point(10, 92, 3);
    Point p2 = Point(-1, 20, 3);
    Point p3 = p1 + p2;
    cin >> p3;
    cout << p1 << endl;
    cout << p2 << endl;
    cout << p3 << endl;
    cout << "Hello, World!\n" << sqrt(1, 1000) << endl;
}

double sqrt(double x, double num) {
    double y = num / x;
    if ((y - x >= 0 && y - x < 0.00001) || (x - y >= 0 && x - y < 0.00001)) {
        return x;
    }
    return sqrt((x + y) / 2, num);
}
