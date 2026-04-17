#include <iostream>
#include <string>
using namespace std;

// Base class
class Vehicle {
public:
    void start() const {
        cout << "Vehicle started" << endl;
    }

    void stop() const {
        cout << "Vehicle stopped" << endl;
    }
};

// Derived class inherits from Vehicle publicly
class Car : public Vehicle {
public:
    void honk() const {
        cout << "Car is honking" << endl;
    }
};

int main() {
    Car myCar;

    // Car can use methods from its base class Vehicle
    myCar.start();
    myCar.honk();
    myCar.stop();

    return 0;
}
