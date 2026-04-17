# Polymorphism

## What is Polymorphism?

Polymorphism is a core concept of Object-Oriented Programming (OOP) where a single interface can represent different underlying forms (data types or classes).

- `poly` means **many**
- `morphism` means **forms**

So polymorphism literally means **many forms**.

## Why Polymorphism?

Polymorphism helps write code that is more flexible, reusable, and easier to maintain.

- It allows a single function or object reference to work with many kinds of objects.
- It reduces the need for repetitive code.
- It helps build systems that can be extended without changing existing code.

## Need for Polymorphism

Polymorphism is needed when we want a general way to use objects from different classes while allowing each class to behave differently.

- It enables one interface to serve multiple implementations.
- It supports code that is easier to scale and modify.
- It lets us treat related objects uniformly while preserving their individual behaviors.

## Real World Example

Think about a remote control that can operate many devices:

- A single `RemoteControl` can work with a `TV`, `DVDPlayer`, or `SoundSystem`.
- The remote has the same buttons, but each device reacts differently when a button is pressed.

This is polymorphism: one control, many device behaviors.

## Coding Example

In C++, polymorphism can be shown using base and derived classes.

```cpp
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal* a1 = new Dog();
    Animal* a2 = new Cat();

    a1->speak(); // Dog barks
    a2->speak(); // Cat meows

    delete a1;
    delete a2;
    return 0;
}
```

Here, `Animal*` can point to different derived objects and call the correct `speak()` implementation at runtime.

## Types of Polymorphism

There are two main types of polymorphism in C++:

1. **Compile-time polymorphism**
2. **Runtime polymorphism**

### 1. Compile-time Polymorphism

Compile-time polymorphism happens when the compiler decides which function to call before the program runs.

Common forms:

- **Function overloading**: multiple functions with the same name but different parameters.
- **Operator overloading**: defining custom behavior for operators like `+`, `-`, `<<`, etc.

Example:

```cpp
#include <iostream>
using namespace std;

class Math {
public:
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
};

int main() {
    Math m;
    cout << m.add(2, 3) << endl;    // calls int add(int, int)
    cout << m.add(2.5, 3.5) << endl; // calls double add(double, double)
    return 0;
}
```

### 2. Runtime Polymorphism

Runtime polymorphism happens when the decision about which function to call is made while the program is running.

This usually uses:

- **Inheritance**
- **Virtual functions**
- **Base class pointers or references**

In C++, runtime polymorphism is often achieved with a base class pointer or reference calling a virtual function that derived classes override.

Example:

```cpp
class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};
```

A `Shape*` can point to either `Circle`, `Rectangle`, or another derived object and call the correct `draw()` at runtime.
