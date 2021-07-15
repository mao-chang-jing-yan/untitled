//
// Created by Xiao Shen on 2021/7/13.
//

#include "Point.h"

Point::Point(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Point Point::operator+(Point p) const {
    Point r = Point(this->x + p.x, this->y + p.y, this->z + p.z);
    return r;
}

Point Point::operator-(Point p) const {
    Point r = Point(this->x - p.x, this->y - p.y, this->z - p.z);
    return r;
}

ostream &operator<<(ostream &os, const Point &c) {
    os << "x:"<< c.x << " y:" << c.y << " z:" << c.z; //以"a+bi"的形式输出
    return os;
}

istream &operator>>(istream &is, Point &c) {
    double x,y,z;
    cout << "请输入x,y,z:" << endl;
    is >> x >> y >>z;
    c.x = x;
    c.y = y;
    c.z = z;
    return is;
}


