#include <iostream>

using namespace std;

class DivisionByZero {
public:
    const char* getError() { return "Division by zero!"; }
};

template <typename T1, typename T2>
double mydiv(const T1& a, const T2& b) {
    if (b == 0) {
        throw DivisionByZero();
    }

    return static_cast<double>(a / b);
}

int main() {
    try {
        double i = mydiv(8.4, 0);
        cout << i << endl;
    } catch(DivisionByZero err) {
        cout << err.getError() << endl;
    }    

    return 0;
}
