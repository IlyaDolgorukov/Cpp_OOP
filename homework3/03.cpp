#include <iostream>

using namespace std;

class Fraction {
private:
    int numerator, denominator;
public:
    Fraction(int a, int b) : numerator(a), denominator(b) {
        if (b == 0) {
            b = 1;
        }
    }
    void print() {
        cout << "Fraction is: " << numerator << "/" << denominator << endl;
    }
    Fraction operator+(Fraction f) {
        int a = numerator * f.denominator;
        int b = denominator * f.numerator;
        denominator *= f.denominator;
        numerator = a + b;
        return *this;
    }
    Fraction operator-(Fraction f) {
        int a = numerator * f.denominator;
        int b = denominator * f.numerator;
        denominator *= f.denominator;
        numerator = a - b;
        return *this;
    }
    Fraction operator*(Fraction f) {
        numerator *= f.numerator;
        denominator *= f.denominator;
        return *this;
    }
    Fraction operator/(Fraction f) {
        numerator *= f.denominator;
        denominator *= f.numerator;
        return *this;
    }
    Fraction operator-() {
        numerator = -numerator;
        denominator = -denominator;
        return *this;
    }
    bool operator==(Fraction f) {
        int a = numerator * f.denominator;
        int b = denominator * f.numerator;
        return a == b;
    }
    bool operator!=(Fraction f) {
        return !(*this == f);
    }
    bool operator<(Fraction f) {
        int a = numerator * f.denominator;
        int b = denominator * f.numerator;
        return a < b;
    }
    bool operator>=(Fraction f) {
        return !(*this < f);
    }
    bool operator>(Fraction f) {
        int a = numerator * f.denominator;
        int b = denominator * f.numerator;
        return a > b;
    }
    bool operator<=(Fraction f) {
        return !(*this > f);
    }
};

int main() {
    Fraction fraction1(3, 7);
    Fraction fraction2(4, 5);
    fraction1 = fraction1 + fraction2;
    fraction1.print();
    cout << endl;

    Fraction fraction3(3, 7);
    Fraction fraction4(4, 5);
    fraction3 = fraction3 - fraction4;
    fraction3.print();
    cout << endl;

    Fraction fraction5(3, 7);
    Fraction fraction6(4, 5);
    fraction5 = fraction5 * fraction6;
    fraction5.print();
    cout << endl;

    Fraction fraction7(3, 7);
    Fraction fraction8(4, 5);
    fraction7 = fraction7 / fraction8;
    fraction7.print();
    cout << endl;

    Fraction fraction9(3, 7);
    fraction9 = -fraction9;
    fraction9.print();
    cout << endl;

    Fraction fraction10(3, 7);
    Fraction fraction11(4, 5);
    
    cout << (fraction10 == fraction11 ? "True" : "False") << endl;
    cout << endl;

    cout << (fraction10 != fraction11 ? "True" : "False") << endl;
    cout << endl;

    cout << (fraction10 > fraction11 ? "True" : "False") << endl;
    cout << endl;

    cout << (fraction10 <= fraction11 ? "True" : "False") << endl;
    cout << endl;

    cout << (fraction10 < fraction11 ? "True" : "False") << endl;
    cout << endl;

    cout << (fraction10 >= fraction11 ? "True" : "False") << endl;

    return 0;
}
