#pragma once
#include <iostream>
#include <Windows.h>
using namespace std;

class Complex
{

    return res;
}
Complex Complex::operator - (const Complex& a) {
    Complex res;
    res.Re = Re - a.Re;
    res.Im = Im - a.Im;
    return res;
}
Complex Complex::operator - (double a) {
    Complex res;
    Complex b(a);
    res = (*this) - b;
    return res;
}
Complex Complex::operator * (const Complex& a) {
    Complex res;
    res.Re = (Re * a.Re) - (Im * a.Im);
    res.Im = (Im * a.Re) + (a.Im * Re);
    return res;
}
Complex Complex::operator * (double a) {
    Complex res;
    Complex b(a);
    res = (*this) * b;
    return res;
}
Complex Complex::operator / (const Complex& a) {
    Complex res;
    res.Re = (Re * a.Re + Im * a.Im) / (pow(a.Re, 2) + pow(a.Im, 2));
    res.Im = (Im * a.Re - a.Im * Re) / (pow(a.Re, 2) + pow(a.Im, 2));
    return res;
}
Complex Complex::operator / (double a) {
    Complex res;
    Complex b(a);
    res = (*this) / b;
    return res;
}
Complex operator + (double a, const Complex& c) {
    Complex res;
    Complex b(a);
    res = b + c;
    return res;
}
Complex operator - (double a, const Complex& c) {
    Complex res;
    Complex b(a);
    res = b - c;
    return res;
}
Complex operator * (double a, const Complex& c) {
    Complex res;
    Complex b(a);
    res = b * c;
    return res;
}
Complex operator / (double a, const Complex& c) {
    Complex res;
    Complex b(a);
    res = b / c;
    return res;
}
Complex Complex::operator - () {
    Complex res(*this);
    res.Re = -res.Re;
    res.Im = -res.Im;
    return res;
}
istream& operator >> (istream& fin, Complex& a) {
    char buf[30];
    fin.getline(buf, 29);
    sscanf(buf, "%lf %lf", &a.Re, &a.Im);
    return fin;
}
ostream& operator << (ostream& out, const Complex& a) {
    if (!a.Re && a.Im)
        out << a.Im << "i";
    if (a.Re && !a.Im)
        out << a.Re;
    if (a.Re && a.Im)
        out << a.Re << showpos << a.Im << noshowpos << "i";
    if (!a.Re && !a.Im)
        out << "0";
    return out;
}

};

