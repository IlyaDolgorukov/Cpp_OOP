#include <iostream>

using namespace std;

class Ex {
private:
    double x;
public:
    Ex(double a) : x(a) { }
    double getEx() {
        return x;
    }
};

class Bar {
private:
    double y;
public:
    Bar() {
        y = 0;
    }
    void set(double a) {
        if ((y + a) > 100) {
            throw Ex(a * y);
        } else {
            y = a;
        }
    }
};

int main() {
    Bar b;
    int num = 1;
    while (num != 0) {
        cout << "Input number: ";
        cin >> num;
        try {
            b.set(num);
        } catch (Ex err) {
            cout << "Exception Ex: " << err.getEx() << endl;
        }
    }    

    return 0;
}
