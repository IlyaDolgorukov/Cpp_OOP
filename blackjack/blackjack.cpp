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
};

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
};

class GenericPlayer : public Hand {
private:
    string name;
public:
    GenericPlayer(string n): name(n) { }
    virtual void IsHitting() = 0;
    bool IsBoosted() {
        return GetTotal() > 21;
    }
    void Bust() const {
        cout << "Player " << name << " has Boost!" << endl;
    }
};

int main() {
    Card card1(king, diamonds, false);
    Card card2(seven, clubs, false);
    Card card3(ten, hearts, false);
    Card card4(ace, diamonds, true);
    Card card5(queen, spades, true);
    
    Hand player;
    player.Add(&card1);
    player.Add(&card2);
    player.Add(&card3);
    player.Add(&card4);
    player.Add(&card5);

    int points = player.GetTotal();
    cout << "Player points = " << points << endl;
    player.Clear();
    points = player.GetTotal();
    cout << "Player points = " << points << endl;

    return 0;
}
