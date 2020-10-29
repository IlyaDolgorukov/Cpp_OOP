#include <iostream>

using namespace std;

enum Sex {
    man,
    woman
};

class Person {
private:
    string name;
    int age;
    Sex sex;
    float weight;
public:
    Person(string n, int a, Sex s, float w) : name(n), age(a), sex(s), weight(w) {}
    void setName(string n) {
        name = n;
    }
    void setAge(int a) {
        age = a;
    }
    void setWeight(float w) {
        weight = w;
    }
    string getName() const { return name; }
    int getAge() const { return age; }
    Sex getSex() const { return sex; }
    float getWeight() const { return weight; }
    void print() const {
        cout << name << ", " << age << ", " << (sex == man ? "Man" : "Woman") << ", " << weight << endl;
    }
};

class Student : public Person {
private:
    int year;
    static int count;
public:
    Student(string n, int a, Sex s, float w, int y) : Person(n, a, s, w), year(y) {
        count++;
    }
    int static getCount() { return count; }
    void setYear(int y) {
        year = y;
    }
    void incYear() {
        year++;
    }
    void print() const {
        cout << Person::getName() << ", " << Person::getAge() << ", " << (Person::getSex() == man ? "Man" : "Woman") << ", " << Person::getWeight() << ", " << year << endl;
    }
};

int Student::count = 0;

int main(int argc, char const *argv[])
{
    Student student1("Vlad", 19, man, 70.0, 1);
    student1.setYear(3);
    student1.print();
    Student student2("Olga", 18, woman, 55.2, 1);
    student2.incYear();
    student2.print();
    Student student3("Ivan", 20, man, 72.5, 4);
    student3.print();
    Student student4("Elena", 17, woman, 48.4, 1);
    student4.print();
    cout << "Count of students = " << Student::getCount();

    return 0;
}
