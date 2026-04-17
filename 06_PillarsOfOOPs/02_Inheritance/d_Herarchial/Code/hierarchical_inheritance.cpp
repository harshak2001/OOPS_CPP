#include <iostream>
using namespace std;

class Vehicle {
public:
    void start() const {
        cout << "Vehicle started" << endl;
    }
};

class Car : public Vehicle {
public:
    void honk() const {
        cout << "Car honks" << endl;
    }
};

class Bike : public Vehicle {
public:
    void ringBell() const {
        cout << "Bike rings bell" << endl;
    }
};

int main() {
    Car myCar;
    Bike myBike;

    myCar.start();
    myCar.honk();

    myBike.start();
    myBike.ringBell();

    return 0;
}
