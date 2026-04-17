#include <iostream>
using namespace std;

class Engine {
public:
    void startEngine() const {
        cout << "Engine started" << endl;
    }
};

class Vehicle : public Engine {
public:
    void move() const {
        cout << "Vehicle is moving" << endl;
    }
};

class Stereo {
public:
    void playMusic() const {
        cout << "Music playing" << endl;
    }
};

class SmartCar : public Vehicle, public Stereo {
};

int main() {
    SmartCar car;
    car.startEngine();
    car.move();
    car.playMusic();
    return 0;
}
