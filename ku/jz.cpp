//
// Created by Xiao Shen on 2021/7/14.
//

#include <cstdlib>
#include <iostream>
#include "jz.h"

using namespace std;

jz::~jz() {
    // 释放
//    for (int i = 0; i < x; i++)
//        delete[] data[i];
//    delete[] data;
}

jz::jz() {
    x = 1;
    y = 1;
    data = (double **) malloc(x * sizeof(double *));
    for (int i = 0; i < x; i++) {
        data[i] = (double *) malloc(y * sizeof(double));
    }
}

jz::jz(int x, int y): x(x), y(y)  {
    this->~jz();
    this->data = (double **) malloc(x * sizeof(double *));
    for (int i = 0; i < x; i++) {
        this->data[i] = (double *) malloc(y * sizeof(double));
        for (int j = 0; j < y; ++j) {
            this->data[i][j] = 0;
            if (i == j){
                this->data[i][j] = 1;
            }
        }
    }
}

jz::jz(int n) {
    x = n;
    y = n;
    this->~jz();
    this->data = (double **) malloc(x * sizeof(double *));
    for (int i = 0; i < x; i++) {
        this->data[i] = (double *) malloc(y * sizeof(double));
        for (int j = 0; j < y; ++j) {
            this->data[i][j] = 0;
            if (i == j){
                this->data[i][j] = 1;
            }
        }
    }
}


jz::jz(const double *data, int x, int y) : x(x), y(y) {
    this->~jz();
    this->data = (double **) malloc(x * sizeof(double *));
    for (int i = 0; i < x; i++) {
        this->data[i] = (double *) malloc(y * sizeof(double));
        for (int j = 0; j < y; ++j) {
            this->data[i][j] = *(data + (i * y) + j);
        }
    }
}


int jz::getX() const {
    return x;
}

void jz::setX(const int x_) {
    jz::x = x_;
}

int jz::getY() const {
    return y;
}

void jz::setY(const int y_) {
    jz::y = y_;
}

void jz::Print() {
    cout << endl;
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j) {
            cout << data[i][j] << " ";
        }
        cout << endl;
    }

}

bool jz::checkSize(jz *j) const {
    return x == j->getX() && y == j->getY();
}

bool jz::checkSize_(jz *j) const {
    return y == j->getX();
}


jz jz::operator+(jz jz1) const {
    if (!checkSize(&jz1)) {
        return jz();
    };
    double a[1][1] = {{0}};
    jz j = jz((double *) a, x, y);
    for (int i = 0; i < x; ++i) {
        for (int k = 0; k < y; ++k) {
            j.data[i][k] = data[i][k] + jz1.data[i][k];
        }
    }
    return j;
}

jz jz::operator-(jz jz1) const {
    if (!checkSize(&jz1)) {
        return jz();
    };
    double a[1][1] = {{0}};
    jz j = jz((double *) a, x, y);
    for (int i = 0; i < x; ++i) {
        for (int k = 0; k < y; ++k) {
            j.data[i][k] = data[i][k] - jz1.data[i][k];
        }
    }
    return j;
}

jz jz::operator*(jz jz1) const {
    if (!checkSize_(&jz1)) {
        return jz();
    };
    double a[1][1] = {{0}};
    jz j = jz((double *) a, x, y);
    for (int i = 0; i < x; ++i) {
        for (int k = 0; k < y; ++k) {
            double sum = 0;
            for (int l = 0; l < y; ++l) {
                sum = sum + data[i][l] * jz1.data[l][k];
            }
            j.data[i][k] = sum;
        }
    }
    return j;
}

jz jz::operator+(double num) const {
    double a[1][1] = {{0}};
    jz j = jz((double *) a, x, y);
    for (int i = 0; i < x; ++i) {
        for (int k = 0; k < y; ++k) {
            j.data[i][k] = data[i][k] + num;
        }
    }
    return j;
}

jz jz::operator-(double num) const {
    double a[1][1] = {{0}};
    jz j = jz((double *) a, x, y);
    for (int i = 0; i < x; ++i) {
        for (int k = 0; k < y; ++k) {
            j.data[i][k] = data[i][k] - num;
        }
    }
    return j;
}

jz jz::operator*(double num) const {
    double a[1][1] = {{0}};
    jz j = jz((double *) a, x, y);
    for (int i = 0; i < x; ++i) {
        for (int k = 0; k < y; ++k) {
            j.data[i][k] = data[i][k] * num;
        }
    }
    return j;
}

jz jz::operator/(double num) const {
    double a[1][1] = {{0}};
    jz j = jz((double *) a, x, y);
    for (int i = 0; i < x; ++i) {
        for (int k = 0; k < y; ++k) {
            j.data[i][k] = data[i][k] / num;
        }
    }
    return j;
}

jz jz::operator%(int num) const {
    double a[1][1] = {{0}};
    jz j = jz((double *) a, x, y);
    for (int i = 0; i < x; ++i) {
        for (int k = 0; k < y; ++k) {
            j.data[i][k] = int(data[i][k]) % num;
        }
    }
    return j;
}

jz operator+(const double num, jz &jz1) {
    double a[1][1] = {{0}};
    jz j = jz((double *) a, jz1.x, jz1.y);
    for (int i = 0; i < jz1.x; ++i) {
        for (int k = 0; k < jz1.y; ++k) {
            j.data[i][k] = jz1.data[i][k] + num;
        }
    }
    return j;
}

jz operator-(double num, jz &jz1) {
    double a[1][1] = {{0}};
    jz j = jz((double *) a, jz1.x, jz1.y);
    for (int i = 0; i < jz1.x; ++i) {
        for (int k = 0; k < jz1.y; ++k) {
            j.data[i][k] = num - jz1.data[i][k];
        }
    }
    return j;
}

jz operator*(double num, jz &jz1) {
    int a[1][1] = {{0}};
    jz j = jz((double *) a, jz1.x, jz1.y);
    for (int i = 0; i < jz1.x; ++i) {
        for (int k = 0; k < jz1.y; ++k) {
            j.data[i][k] = jz1.data[i][k] * num;
        }
    }
    return j;
}

jz operator/(double num, jz &jz1) {
    double a[1][1] = {{0}};
    jz j = jz((double *) a, jz1.x, jz1.y);
    for (int i = 0; i < jz1.x; ++i) {
        for (int k = 0; k < jz1.y; ++k) {
            j.data[i][k] = num / jz1.data[i][k];
        }
    }
    return j;
}

jz operator%(int num, jz &jz1) {
    double a[1][1] = {{0}};
    jz j = jz((double *) a, jz1.x, jz1.y);
    for (int i = 0; i < jz1.x; ++i) {
        for (int k = 0; k < jz1.y; ++k) {
            j.data[i][k] = num % int(jz1.data[i][k]);
        }
    }
    return j;
}

jz *jz::R(int r1, double p1, int r2, double p2) {
    jz *j = this;
    for (int l = 0; l < y; ++l) {
        j->data[r2][l] = (j->data[r1][l] * p1) + (j->data[r2][l] * p2);
    }
    return j;
}

jz *jz::A() {
    jz *j = this;

    return j;
}

jz *jz::Copy() {
    double a[1][1] = {{0}};
    jz *j = new jz((double *) a, x, y);
    for (int i = 0; i < x; ++i) {
        for (int k = 0; k < y; ++k) {
            j->data[i][k] = data[i][k];
        }
    }
    return j;
}

jz jz::E(int x_, int y_) {
    return jz(x_, y_);
}

jz *jz::T() {
    double a[1][1] = {{0}};
    double **data_ = this->data;
    this->~jz();
    this->data = (double **) malloc(y * sizeof(double *));
    for (int i = 0; i < y; i++) {
        this->data[i] = (double *) malloc(x * sizeof(double));
        for (int j = 0; j < x; ++j) {
            this->data[i][j] = data_[j][i];
        }
    }
    int tmp = x;
    x = y;
    y = tmp;
    return this;
}
















