# Pure Virtual Functions and Abstract Classes in C++

Last Updated : 15 Oct, 2025

A pure virtual function is a virtual function with no implementation in the base class, declared using `= 0`. A class with at least one pure virtual function is an abstract class that cannot be instantiated and serves as a blueprint for derived classes, which must provide their own implementation.

- A class with at least one pure virtual function becomes an abstract class and Objects of abstract classes cannot be created directly.
- Abstract classes are used to define interfaces and ensure common structure among derived classes.
- Useful in polymorphism where different classes share the same interface but have different behaviors.
- A pure virtual function forces derived classes to override it.
- `virtual void draw() = 0;` declares a pure virtual function, forcing derived classes to provide their own implementation.

#include <iostream>

using namespace std;

​

class Shape {

public:

    virtual void draw() \= 0; // Pure virtual function

};

​

class Circle : public Shape {

public:

    void draw() override {

        cout << "Drawing Circle\\n";

    }

};

​

int main() {

    // Error in the below line : Cannot create

    // object of abstract class

    // Shape s;

    // Pointer to abstract class

    Shape\* s \= new Circle();

    // Output: Drawing Circle

    s\->draw();

    delete s;

}

**Output**

Drawing Circle

**Explanation**: This example shows an abstract class `Shape` with a pure virtual function `draw()`. `Circle` overrides `draw()`, and using a `Shape` pointer to a `Circle` demonstrates polymorphism, outputting Drawing Circle.
