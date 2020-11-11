#include <iostream>

using namespace std;

template<typename T> 
class Pair {
private:
    string fr;
    T sec;
public:
    Pair(string f, T s): fr(f), sec(s) {}
    string first() const {
        return fr;
    }
    T second() const {
        return sec;
    }
};

template<typename T2>
class StringValuePair: public Pair<T2> {
public:
    StringValuePair(string a, T2 b) : Pair<T2>(a, b) { }
};

int main()
{
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    return 0;
}
