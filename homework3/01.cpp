#include <iostream>

using namespace std;

struct Point
{
    int x;
    int y;
};

class Figure {
public:
    virtual float area() = 0;
};

class Parallelogram: public Figure {
private:
    Point p1; // Top left
    Point p2; // Top right
    Point p3; // Bottom right
    Point p4; // Bottom left
public:
    Parallelogram(Point a, Point b, Point c, Point d) : p1(a), p2(b), p3(c), p4(d) {}
    float area() override {
        float length = p2.x - p1.x;
        float height = p1.y - p4.y;
        return length * height;
    }
};

class Circle: public Figure {
private:
    int radius;
    const float pi = 3.14;
public:
    Circle(int r) : radius(r) {}
    float area() override {
        return pi * radius * radius;
    }
};

class Rectangle: public Parallelogram {
public:
    Rectangle(Point a, Point b, Point c, Point d) : Parallelogram(a, b, c, d) {}
    float area() override {
        return Parallelogram::area();
    }
};

class Square: public Parallelogram {
public:
    Square(Point a, Point b, Point c, Point d) : Parallelogram(a, b, c, d) {}
    float area() override {
        return Parallelogram::area();
    }
};

class Rhombus: public Parallelogram {
public:
    Rhombus(Point a, Point b, Point c, Point d) : Parallelogram(a, b, c, d) {}
    float area() override {
        return Parallelogram::area();
    }
};


int main() {
    Parallelogram parallelogram({20, 50}, {80, 50}, {60, 20}, {0, 20});
    cout << "Area of parallelogram = " << parallelogram.area() << endl;

    Circle circle(32);
    cout << "Area of circle = " << circle.area() << endl;

    Rectangle rectangle({20, 50}, {80, 50}, {80, 20}, {20, 20});
    cout << "Area of rectangle = " << rectangle.area() << endl;

    Square square({20, 50}, {50, 50}, {50, 20}, {20, 20});
    cout << "Area of square = " << square.area() << endl;

    Rhombus rhombus({10, 40}, {40, 50}, {70, 40}, {40, 30});
    cout << "Area of rhombus = " << rhombus.area() << endl;

    return 0;
}
