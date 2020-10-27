#include <iostream>
#include <cmath>

using namespace std;

class Power {
    public:
    float num1;
    float num2;

    void set(float x, float y) {
        num1 = x;
        num2 = y;
    }

    void calculate() {
        cout << pow(num1, num2);
    }
};

int main()
{
    Power power;
    power.set(2.2, 3.1);
    power.calculate();

    return 0;
}
