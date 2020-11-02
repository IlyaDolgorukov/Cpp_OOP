#include <iostream>

using namespace std;

class Fruit {
private:
    string name;
    string color;
public:
    Fruit(string n, string c) : name(n), color(c) {}
    string getName() const { return name; }
    string getColor() const { return color; }
    void setName(string n) {
        name = n;
    }
};

class Apple : public Fruit {
public:
    Apple(string c) : Fruit("apple", c) {}
};

class Banana : public Fruit {
public:
    Banana() : Fruit("banana", "yellow") {}
};

class GrannySmith : public Apple {
public:
    GrannySmith() : Apple("green") {
        setName("Granny Smith apple");
    }
};

int main()
{
    Apple a("red");
    Banana b;
    GrannySmith c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}

