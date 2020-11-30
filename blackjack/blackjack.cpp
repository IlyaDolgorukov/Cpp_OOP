#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>

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
        if (!m_IsFaceUp) {
            return -1;
        }
        return m_Rank < 10 ? m_Rank + 1 : 10;
    }
    friend ostream& operator<< (ostream& out, Card& card);
};

ostream& operator<< (ostream& out, Card& card) {
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
protected:
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
                if (val >= 0) {
                    if (val != ace) {
                        total += val;
                    } else {
                        aceCnt++;
                    }
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
    friend ostream& operator<< (ostream& out, GenericPlayer& p);
};

ostream& operator<< (ostream& out, GenericPlayer& p) {
    vector<Card*> cards = p.m_Cards;
    out << "Player " << p.GetName() << " cards: | ";
    if (cards.size() > 0) {
        vector<Card*>::iterator it;
        for (it = cards.begin(); it != cards.end(); ++it) {
            cout << *(*it) << " | ";
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
        cout << "Player " << GetName() << ", do you wanna card? (y/n): ";
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

class Deck : public Hand {
public:
    Deck() {
        Populate();
    }
    void Populate() {
        for (int i = spades; i <= diamonds; ++i) {
            for (int j = ace; j <= king; ++j) {
                suit s = static_cast<suit>(i);
                ranks r = static_cast<ranks>(j);
                Add(new Card(r, s, true));
            }
        }
    }
    void Shuffle() {
        srand(static_cast<unsigned int>(time(0)));
        random_shuffle(m_Cards.begin(), m_Cards.end());
    }
    void Deal(Hand& aHand) {
        aHand.Add(m_Cards.back());
        m_Cards.pop_back();
    }
    void AdditionalCards(GenericPlayer& aGenericPlayer) {
        while (aGenericPlayer.IsHitting()) {
            Deal(aGenericPlayer);
            cout << aGenericPlayer << endl;
            if (aGenericPlayer.IsBoosted()) {
                aGenericPlayer.Bust();
                break;
            }
        }        
    }
};

class Game {
private:
    Deck deck;
    House diller;
    vector<Player> players;
public:
    Game(vector<string> n) {
        vector<string>::iterator it;
        for (it = n.begin(); it != n.end(); ++it) {
            players.push_back(Player(*it));
        }
        deck.Shuffle();
    }
    void play() {
        deck.Deal(diller);
        deck.Deal(diller);
        diller.FlipFirstCard();

        vector<Player>::iterator it;
        for (it = players.begin(); it != players.end(); ++it) {
            deck.Deal(*it);
            deck.Deal(*it);
            cout << *it << endl;
        }
        cout << diller << endl;
        
        for (it = players.begin(); it != players.end(); ++it) {
            deck.AdditionalCards(*it);
        }
        diller.FlipFirstCard();
        deck.AdditionalCards(diller);

        if (diller.IsBoosted()) {
            for (it = players.begin(); it != players.end(); ++it) {
                if (!(*it).IsBoosted()) {
                    (*it).Win();
                }
            }
        } else {
            int dillerTotal = diller.GetTotal();
            for (it = players.begin(); it != players.end(); ++it) {
                if (!(*it).IsBoosted()) {
                    if ((*it).GetTotal() > dillerTotal) {
                        (*it).Win();
                    } else if ((*it).GetTotal() < dillerTotal) {
                        (*it).Lose();
                    } else {
                        (*it).Push();
                    }
                }
            }
        }
        
        for (it = players.begin(); it != players.end(); ++it) {
            (*it).Clear();
        }
        diller.Clear();
        deck.Clear();
    }
    void replay() {
        deck.Populate();
        deck.Shuffle();
        play();
    }
};

int main() {
    vector<string> names;
    string name;

    while (true) {
        cout << "Input Player name or type 'play' to start the game: ";
        cin >> name;
        if (name == "play" && names.size() > 0) {
            break;
        } else {
            names.push_back(name);
        }
    }

    Game game(names);

    string answer;
    while (true) {
        game.play();
        cout << "Wanna play again? (y/n): ";
        cin >> answer;
        if (answer == "y") {
            game.replay();
        } else {
            break;
        }
    }

    return 0;
}
