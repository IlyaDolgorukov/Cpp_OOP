#include <iostream>

using namespace std;

class Stack {
    private:
    int arr[10];
    int ln = 0;

    public:
    void reset() {
        ln = 0;
        for (int i = 0; i < 10; i++) {
            arr[i] = 0;
        }
    }
    bool push(int x) {
        if (ln < 10) {
            arr[ln] = x;
            ln += 1;
            return true;
        } else {
            return false;
        }
    }
    int pop() {
        if (ln > 0) {
            ln -= 1;
        }
        int x = arr[ln];
        arr[ln] = 0;
        if (x == 0) {
            cout << "There are no values in the stack";
        }
        return x;
    }
    void print() {
        cout << "( ";
        for (int i = 0; i < ln; i++) {
            cout << arr[i] << " ";
        }
        cout << ")" << endl;
    }
};

int main()
{
    Stack stack;
    stack.reset();
    stack.print();
    
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    
    stack.pop();
    stack.print();
    
    stack.pop();
    stack.pop();
    stack.print();
    
    return 0;
}
