#include <iostream>
using namespace std;

class Animal {
public:
    // virtual makes speak() eligible for runtime polymorphism
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    // override
    void speak() {
        cout << "Dog barks" << endl;
    }
};

int main() {
    // Upcasting: storing a derived object in a base class pointer.
    // This is safe and implicit.
    Animal* a = new Dog();

    // Because speak() is virtual, this call resolves at runtime.
    // Output: Dog barks
    a->speak();

    // If Animal::speak() were not virtual, the call above would use
    // Animal::speak() instead of Dog::speak(). That is compile-time binding.

    // Downcasting example (commented out because it is unsafe if used wrong):
    // Dog* d = dynamic_cast<Dog*>(a);
    // if (d) {
    //     d->speak();
    // }

    delete a;
    return 0;
}
