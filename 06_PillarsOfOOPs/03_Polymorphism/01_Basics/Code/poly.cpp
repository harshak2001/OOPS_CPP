#include <iostream>
using namespace std;

class Animal {
public:
    virtual void sound() {
        cout << "Some generic sound" << endl;
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Woof! Woof!" << endl;
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Meow! Meow!" << endl;
    }
};

int main() {
    Animal* animal1 = new Dog();
    Animal* animal2 = new Cat();
    
    animal1->sound();  // Output: Woof! Woof!
    animal2->sound();  // Output: Meow! Meow!
    
    delete animal1;
    delete animal2;
    
    return 0;
}