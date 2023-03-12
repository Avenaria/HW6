#pragma once
class Fraction
{
    int sign; 
    int intPart; 
    int numerator; 
    int denominator; 
  
    void GetMixedView(); 
    void Cancellation(); 
    void GetIntPart(); 
public:
    Fraction() :Fraction(0, 1) {};
    Fraction(int, int, int = 0, int = 1);
    Fraction operator + (const Fraction&);
    Fraction operator + (int);
    Fraction operator - (const Fraction&);
    Fraction operator - (int);
    Fraction operator * (const Fraction&);
    Fraction operator * (int);
    Fraction operator / (const Fraction&);
    Fraction operator / (int);
    Fraction  operator - ();
    friend Fraction operator + (int, const Fraction&);
    friend Fraction operator - (int, const Fraction&);
    friend Fraction operator * (int, const Fraction&);
    friend Fraction operator / (int, const Fraction&);
    operator double();
     bool operator > (const Fraction&);
    bool operator < (const Fraction&);
    bool operator >= (const Fraction&);
    bool operator <= (const Fraction&);
    bool operator != (const Fraction&);
    bool operator == (const Fraction&);
    friend istream& operator >> (istream&, Fraction&);
    friend ostream& operator << (ostream&, const Fraction&);
};
void Fraction::GetMixedView() {
    GetIntPart();
    Cancellation();
}
void Fraction::Cancellation() {
    if (numerator) {
        int m = denominator,
            n = numerator,
            ost = m % n;
        while (ost) {
            m = n; n = ost;
            ost = m % n;
        }
        int nod = n;
        if (nod != 1) {
            numerator /= nod; denominator /= nod;
        }
    }
}
void Fraction::GetIntPart() {
    if (numerator >= denominator) {
        intPart += (numerator / denominator);
        numerator %= denominator;
    }
}
Fraction::Fraction(int n, int d, int i, int s) {
    intPart = i;
    numerator = n;
    denominator = d;
    sign = s;
    GetMixedView();
}
Fraction Fraction::operator + (const Fraction& a) {
    Fraction res;
    res.numerator = sign * (intPart * denominator + numerator) * a.denominator +
        a.sign * (a.intPart * a.denominator + a.numerator) * denominator;
    res.denominator = denominator * a.denominator;
    if (res.numerator < 0) {
        res.numerator *= -1;
        res.sign = -1;
    }
    res.GetMixedView();
    return res;
}
Fraction Fraction::operator + (int a) {
    Fraction res;
    Fraction b(0, 1, abs(a), a / abs(a));
    res = (*this) + b;
    return res;
}
Fraction Fraction::operator - (const Fraction& a) {
    Fraction res;
    res.numerator = sign * (intPart * denominator + numerator) * a.denominator -
        a.sign * (a.intPart * a.denominator + a.numerator) * denominator;
    res.denominator = denominator * a.denominator;
    if (res.numerator < 0) {
        res.numerator *= -1;
        res.sign = -1;
    }
    res.GetMixedView();
    return res;
}
Fraction Fraction::operator - (int a) {
    Fraction res;
    Fraction b(0, 1, abs(a), a / abs(a));
    res = (*this) - b;
    return res;
}
Fraction Fraction::operator*(const Fraction& a) {
    Fraction res;
    res.numerator = sign * (intPart * denominator + numerator) * a.numerator;
    res.denominator = denominator * a.denominator;
    if (res.numerator < 0) {
        res.numerator *= -1;
        res.sign = -1;
    }
    res.GetMixedView();
    return res;
}
Fraction Fraction::operator*(int a) {
    Fraction res;
    Fraction b(0, 1, abs(a), a / abs(a));
    res = (*this) * b;
    return res;
}
Fraction Fraction::operator/(const Fraction& a) {
    Fraction res;
    res.numerator = sign * (intPart * denominator + numerator) * a.denominator;
    res.denominator = denominator * a.numerator;
    if (res.numerator < 0) {
        res.numerator *= -1;
        res.sign = -1;
    }
    res.GetMixedView();
    return res;
}
Fraction Fraction::operator/(int a) {
    Fraction res;
    Fraction b(0, 1, abs(a), a / abs(a));
    res = (*this) / b;
    return res;
}
Fraction operator + (int a, const Fraction& c) {
    Fraction res;
    Fraction b(0, 1, abs(a), a / abs(a));
    res = b + c;
    return res;
}
Fraction operator - (int a, const Fraction& c) {
    Fraction res;
    Fraction b(0, 1, abs(a), a / abs(a));
    res = b - c;
    return res;
}
Fraction operator*(int a, const Fraction& c) {
    Fraction res;
    Fraction b(0, 1, abs(a), a / abs(a));
    res = b * c;
    return res;
}
Fraction operator/(int a, const Fraction& c) {
    Fraction res;
    Fraction b(0, 1, abs(a), a / abs(a));
    res = b / c;
    return res;
}
Fraction Fraction::operator-() {
    Fraction res(*this);
    res.sign = -res.sign;
    return res;
}
Fraction::operator double() {
    return (double)sign * (intPart * denominator + numerator) / denominator;
}
istream& operator >> (istream& fin, Fraction& a) {
    char buf[30];
    fin.getline(buf, 29);
    
    char* ps = strchr(buf, '/');
    
    if (ps == NULL) {
        
        sscanf(buf, "%d", &a.intPart);
        a.numerator = 0;
        a.denominator = 1;
        if (a.intPart >= 0)
            a.sign = 1;
        else {
            a.sign = -1;
            a.intPart = -a.intPart;
        }
        return fin;
    }
   
    if (strchr(buf, ' ') == NULL) {
        a.intPart = 0;
        
        sscanf(buf, "%d/%d", &a.numerator, &a.denominator);
        
        if (a.numerator > 0)
            a.sign = 1;
        else {
            a.sign = -1;
            a.numerator = -a.numerator;
        }
        a.GetMixedView();
        return fin;
    }
    
    sscanf(buf, "%d %d/%d", &a.intPart, &a.numerator, &a.denominator);
    if (a.intPart > 0)
        a.sign = 1;
    else {
        a.sign = -1;
        a.intPart = -a.intPart;
    }
    a.GetMixedView();
    return fin;
}
ostream& operator << (ostream& out, const Fraction& a) {
    if (a.sign < 0)
        out << "-";
    if (a.intPart)
        out << a.intPart << " ";
    if (a.numerator)
        out << a.numerator << "/" << a.denominator;
    if (a.intPart == 0 && a.numerator == 0)
        out << "0";
    out << " ";
    return out;
}





};

