#include <iostream>
using namespace std;

class Animal {
public:
    void eat() const {
        cout << "Animal eats" << endl;
    }
};

class Mammal : public Animal {
public:
    void breathe() const {
        cout << "Mammal breathes" << endl;
    }
};

class Dog : public Mammal {
public:
    void bark() const {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();      // inherited from Animal through Mammal
    myDog.breathe();  // inherited from Mammal
    myDog.bark();     // defined in Dog
    return 0;
}
