# Operator Overloading

## What is Operator Overloading?

Operator overloading is a compile-time polymorphism feature in C++ that allows user-defined types to use operators like `+`, `-`, `*`, `<<`, and more.

- It gives custom classes natural syntax.
- It lets objects behave more like built-in types.
- It improves code readability and usability.

## Why Use Operator Overloading?

- Use `a + b` instead of a named function like `add(a, b)`.
- Let `cout << obj` print custom objects directly.
- Keep the interface consistent with standard types.

## Example

A class can overload operators to define how operations should work for its objects.

```cpp
#include <iostream>
using namespace std;

class Complex {
public:
    double real;
    double imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real << " + " << c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex sum = c1 + c2;

    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    return 0;
}
```

## Notes

- `operator+` defines how two `Complex` objects are added.
- `operator<<` allows `cout` to print a `Complex` object.
- The example is implemented in `OpOverloading.cpp`.
