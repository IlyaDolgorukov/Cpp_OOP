#include <iostream>

using namespace std;

class OffTheField {
private:
    int x;
    int y;
public:
    OffTheField(int a, int b): x(a), y(b) { }
    void getErr() {
        cout << "Robot is off the field!!! X: " << x << ", Y: " << y << endl;
    }
};

class IllegalCommand {
private:
    int command;
public:
    IllegalCommand(int c): command(c) {}
    void getErr() {
        cout << "Illegal Command!!! Command: " << command << endl;
    }
};

class Robot {
private:
    int x;
    int y;
public:
    Robot(int a, int b): x(a), y(b) {
        isInField();
    }
    void isInField() {
        if (
            x < 1 || y < 1 || x > 10 || y > 10
        ) {
            throw OffTheField(x, y);
        }
    }
    void move(int c) {
        switch (c) {
            case 0: cout << "Goodbye!" << endl; break;
            case 1: y++; break;
            case 2: x++; break;
            case 3: y--; break;
            case 4: x--; break;
            default: throw IllegalCommand(c);
        }
        if (c > 0) {
            isInField();
            cout << "Robot coords is X: " << x << ", Y: " << y << endl; 
        } 
    }
};

int main() {
    Robot robot(2, 5);
    int comm = -1;
    while (comm != 0) {
        cout << "Input command (0 = stop | 1 = up | 2 = right | 3 = down | 4 = left): ";
        cin >> comm;
        try {
            robot.move(comm);
        } catch (OffTheField err) {
            err.getErr();
        } catch (IllegalCommand err) {
            err.getErr();
        }
    }

    return 0;
}
