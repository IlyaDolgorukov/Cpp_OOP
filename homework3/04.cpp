#include <iostream>

using namespace std;

enum Suit {spades, hearts, clubs, diamonds};
enum Val {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};

class Card {
private:
    Val val;
    Suit suit;
    bool position;
public:
    Card(Val v, Suit s, bool p) : val(v), suit(s), position(p) {}
    void Flip() {
        position = !position;
    }
    int GetValue() {
        return val < 10 ? val + 1 : 10;
    }
};

int main() {
    Card card(ace, diamonds, false);
    cout << "Value is " << card.GetValue() << endl;

    return 0;
}
