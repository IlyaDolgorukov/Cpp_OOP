#include <iostream>

using namespace std;

class Car {
private:
    string company;
    string model;
public:
    Car(string c, string m) : company(c), model(m) {
        cout << "Class: Car, Company: " << company << ", Model: " << model << endl;
    }
    string getCompany() const { return company; }
    string getModel() const { return model; }
};

class PassengerCar: virtual public Car {
public: 
    PassengerCar(string c, string m) : Car(c, m) {
        cout << "Class: PassengerCar, Company: " << getCompany() << ", Model: " << getModel() << endl;
    }
};

class Bus: virtual public Car {
public:
    Bus(string c, string m) : Car(c, m) {
        cout << "Class: Bus, Company: " << getCompany() << ", Model: " << getModel() << endl;
    }
};

class Minivan: public PassengerCar, public Bus {
public:
    Minivan(string c, string m) : PassengerCar(c, m), Bus(c, m), Car(c, m) {
        cout << "Class: Minivan, Company: " << getCompany() << ", Model: " << getModel() << endl;
    }
};

int main() {
    Car car("Some company", "Some model");
    cout << endl;

    PassengerCar passengerCar("Ford", "Focus");
    cout << endl;

    Bus bus("Scania", "Higer");
    cout << endl;
    
    Minivan minivan("Opel", "Vivaro");

    return 0;
}
