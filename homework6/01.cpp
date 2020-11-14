#include <iostream>
#include <cctype>

using namespace std;

int main() {
    int num;
    string str;
    bool isnum = false;

    while (!isnum) {
        isnum = true;
        cout << "Please inter an integer number: ";
        getline(cin, str);
        for (int i = 0; i < str.size(); ++i) {
            if (!isdigit(str[i])) {
                isnum = false;
                cout << "Your number is wrong, try again" << endl;
                break;
            }
        }
    }
        
    num = stoi(str);
    cout << "Great! Your number was: " << num << endl;

    return 0;
}
