#include <iostream>
using namespace std;

class Animal {
public:
    void eat() const {
        cout << "Animal eats" << endl;
    }
};

class Dog : public Animal {
public:
    void bark() const {
        cout << "Dog barks" << endl;
    }
};

int main() {
    Dog myDog;
    myDog.eat();   // inherited from Animal
    myDog.bark();  // defined in Dog
    return 0;
}
