//
// Created by Xiao Shen on 2021/7/14.
//

#ifndef UNTITLED_JZ_H
#define UNTITLED_JZ_H


class jz {
private:
    double **data;
    int x{}, y{};
public:
    jz();
    explicit jz(int n);
    jz(int x, int y);
    jz(const double *data, int x, int y);

    ~jz();


    bool checkSize(jz *j) const;

    bool checkSize_(jz *j) const;

    int getX() const;

    void setX(int x_);

    int getY() const;

    void setY(int y_);

    void Print();

    jz *R(int r1, double p1, int r2, double p2);

    jz *A();

    static jz E(int x, int y);

    jz *T();

    jz *Copy();

    jz operator+(jz jz1) const;

    jz operator-(jz jz1) const;

    jz operator*(jz jz1) const;

    jz operator+(double num) const;

    jz operator-(double num) const;

    jz operator*(double num) const;

    jz operator/(double num) const;

    jz operator%(int num) const;


    friend jz operator+(double num, jz &jz1);

    friend jz operator-(double num, jz &jz1);

    friend jz operator*(double num, jz &jz1);

    friend jz operator/(double num, jz &jz1);

    friend jz operator%(int num, jz &jz1);


};


#endif //UNTITLED_JZ_H
