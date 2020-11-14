#include <iostream>
#include <vector>

using namespace std;

enum ranks {ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};
enum suit {spades, hearts, clubs, diamonds};

class Card {
private:
    ranks m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
public:
    Card(ranks r, suit s, bool p) : m_Rank(r), m_Suit(s), m_IsFaceUp(p) {}
    void Flip() {
        m_IsFaceUp = !m_IsFaceUp;
    }
    int GetValue() {
        return m_Rank < 10 ? m_Rank + 1 : 10;
    }
    friend ostream& operator<< (ostream& out, const Card& card);
};

ostream& operator<< (ostream& out, const Card& card) {
    if (card.m_IsFaceUp) {
        string rnks[13] = {"ace", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "jack", "queen", "king"};
        string sts[4] = {"spades", "hearts", "clubs", "diamonds"};
        out << rnks[card.m_Rank] << " " << sts[card.m_Suit];
    } else {
        out << "XX";
    }

    return out;
}

class Hand {
private:
    vector<Card*> m_Cards;
    int optimalAceCount(int cnt, int total) const {
        int count = cnt * 11;
        if ((total + count) > 21) {
            for (int i = 1; i <= cnt; i++) {
                count -= 10;
                if ((total + count) <= 21) break;
            }
        }

        return count;
    }
public:
    void Add(Card* pCard) {
        m_Cards.push_back(pCard);
    }
    void Clear() {
        for (auto item : m_Cards) delete item;
        m_Cards.clear();
    }
    int GetTotal() {
        int val = 0;
        int total = 0;
        int aceCnt = 0;
        if (m_Cards.size() > 0) {
            vector<Card*>::iterator it;
            for (it = m_Cards.begin(); it != m_Cards.end(); ++it) {
                Card card = *(*it);
                val = card.GetValue();
                if (val != ace) {
                    total += val;
                } else {
                    aceCnt++;
                }
            }
            if (aceCnt > 0) {
                total += optimalAceCount(aceCnt, total);
            }
        }
        
        return total;
    }
    void FlipCard(int index) {
        if (m_Cards.size() > index) {
            Card& card = *m_Cards.at(index);
            card.Flip();
        }
    }
    vector<Card*> GetCards() const {
        return m_Cards;
    }
};

class GenericPlayer : public Hand {
private:
    string name;
public:
    GenericPlayer(string n): name(n) { }
    virtual bool IsHitting() = 0;
    bool IsBoosted() {
        return GetTotal() > 21;
    }
    void Bust() const {
        cout << "Player " << name << " has Boost!" << endl;
    }
    string GetName() const {
        return name;
    }
    friend ostream& operator<< (ostream& out, const GenericPlayer& p);
};

ostream& operator<< (ostream& out, GenericPlayer& p) {
    vector<Card*> cards = p.GetCards();
    out << "Player " << p.GetName() << " cards: | ";
    if (cards.size() > 0) {
        vector<Card*>::iterator it;
        for (it = cards.begin(); it != cards.end(); ++it) {
            Card card = *(*it);
            out << card << " | ";
        }
    }
    out << endl << "Total scores: " << p.GetTotal();
    
    return out;
}

class Player : public GenericPlayer {
public:
    Player(string n): GenericPlayer(n) { }
    bool IsHitting() {
        string ans;
        cout << "Do you wanna card? (y/n): ";
        cin >> ans;
        
        return ans == "y";
    }
    void Win() const {
        cout << "Player " << GetName() << " won!" << endl;
    }
    void Lose() const {
        cout << "Player " << GetName() << " lost!" << endl;
    }
    void Push() const {
        cout << "Player " << GetName() << " drew!" << endl;
    }
};

class House : public GenericPlayer {
public:
    House(): GenericPlayer("House") { }
    bool IsHitting() {
        return GetTotal() <= 16;
    }
    void FlipFirstCard() {
        FlipCard(0);
    }
};

int main() {
    Card card1(king, diamonds, false);
    Card card2(seven, clubs, false);
    Card card3(ten, hearts, false);
    Card card4(ace, diamonds, false);
    Card card5(queen, spades, false);

    House house;
    house.Add(&card1);
    house.Add(&card2);
    house.FlipFirstCard();
    cout << house << endl;

    Player player("John");
    player.Add(&card3);
    player.Add(&card4);
    cout << player << endl;
    if (player.IsHitting()) {
        player.Add(&card5);
        cout << player << endl;
        player.Win();
    }

    return 0;
}
