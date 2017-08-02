#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <sstream>

using namespace std;

class Rational {
public:

    int num;
    int den;

    Rational() {
        num = 0;
        den = 1;
    }
    Rational(int numerator, int denominator) {
        if(numerator == 0) {
            den = 1;
            num = 0;
            return;
        }
        int m = NOD(numerator, denominator);
        num = numerator / m;
        den = denominator / m;
        if(den < 0) {
            den = -den;
            num = -num;
        }
    }

    bool operator ==(const Rational& a) {
        return (a.Numerator() == num && a.Denominator() == den);
    }


    bool operator>(const Rational& a) {
        int znam = a.Denominator() * den / NOD(a.Denominator(), den);
        if (num * (znam/den) - a.Numerator() * (znam / a.Denominator()) > 0) {
            return true;
        } else {
            return false;
        }
    }

    Rational operator+(const Rational& a) {
        int znam = a.Denominator() * den / NOD(a.Denominator(), den);
        return Rational(num*(znam/den) + a.Numerator() * (znam/a.Denominator()), znam);
    }

    Rational operator-(const Rational& a) {
        int znam = a.Denominator() * den / NOD(a.Denominator(), den);
        return Rational(num*(znam/den) - a.Numerator() * (znam/a.Denominator()), znam);
    }

    Rational operator*(const Rational& a) {
        return Rational(a.Numerator()*num, a.Denominator()*den);
    }

    Rational operator/(const Rational& a) {
        return Rational(num * a.Denominator(), den * a.Numerator());
    }

    int Numerator() const {
        return num;
    }
    int Denominator() const {
        return den;
    }

private:
    int NOD(int a, int b) {
        bool is_neg = false;
        if(a <= 0 && b > 0) {
            if(a != 0) {
                a = -a;
            }
            is_neg = true;
        } else if(a >= 0 && b < 0) {
            b = -b;
            is_neg = true;
        }
        while (a !=0 && b != 0) {
            if (a > b) {
                a = a % b;
            } else {
                b = b % a;
            }
        }
        if(!is_neg) {
            return (a+b);
        } else {
            return -(a+b);
        }
    }
};

ostream& operator<<(ostream& stream, const Rational& a) {
    stream << a.Numerator() << '/' << a.Denominator();
    return stream;
}

istream& operator>>(istream& stream,  Rational& a) {
    string tmp = "";
    getline(stream, tmp, ' ');
    istringstream ss(tmp);
    getline(ss, tmp, '/');
    int n, d;
    n = atoi(tmp.c_str());
    getline(ss, tmp);
    d = atoi(tmp.c_str());
    a = Rational(n, d);
    return stream;
}



int main() {
    return 0;
}
