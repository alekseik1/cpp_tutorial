#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

class Rational {
public:
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

    Rational operator+(const Rational& a) {
        int znam = a.Denominator() * den / NOD(a.Denominator(), den);
        return Rational(num*(znam/den) + a.Numerator() * (znam/a.Denominator()), znam);
    }

    Rational operator-(const Rational& a) {
        int znam = a.Denominator() * den / NOD(a.Denominator(), den);
        return Rational(num*(znam/den) - a.Numerator() * (znam/a.Denominator()), znam);
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
    int num;
    int den;
};

int main() {
    {
        Rational r1(4, 6);
        Rational r2(2, 3);
        bool equal = r1 == r2;
        if (!equal) {
            cout << "4/6 != 2/3" << endl;
            return 1;
        }
    }

    {
        Rational a(2, 3);
        Rational b(4, 3);
        Rational c = a + b;
        bool equal = c == Rational(2, 1);
        if (!equal) {
            cout << "2/3 + 4/3 != 2" << endl;
            return 2;
        }
    }

    {
        Rational a(5, 7);
        Rational b(2, 9);
        Rational c = a - b;
        bool equal = c == Rational(31, 63);
        if (!equal) {
            cout << "5/7 - 2/9 != 31/63" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
