//
// Created by Xiao Shen on 2021/7/13.
//

#ifndef UNTITLED1_POINT_H
#define UNTITLED1_POINT_H

#include <iostream>
#include <string>
using namespace std;
class Point {
private:
    double x;
    double y;
    double z;
public:
    Point();

    Point(double x, double y, double z);

    Point operator+(Point p) const;

    Point operator-(Point p) const;

    friend ostream & operator<<( ostream & os,const Point & c);
    friend istream & operator>>( istream & is,Point & c);

};


#endif //UNTITLED1_POINT_H
