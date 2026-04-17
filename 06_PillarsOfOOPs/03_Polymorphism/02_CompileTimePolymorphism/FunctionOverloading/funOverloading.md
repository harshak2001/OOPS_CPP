# Function Overloading

## What is Function Overloading?

Function overloading is a compile-time polymorphism technique where multiple functions have the same name but different parameter lists.

- The compiler selects the correct function based on the number, type, or order of arguments.
- It improves readability and keeps related operations grouped under a single name.

## Why Use Function Overloading?

- Use one function name for similar operations.
- Let the compiler choose the best match automatically.
- Create cleaner, easier-to-understand code.

## Example Scenarios

You can overload functions when:

- the number of parameters differs
- the parameter types differ
- the parameter order differs

For example, all of these are valid overloads of `sum()`:

- `int sum(int a, int b)`
- `int sum(int a, int b, int c)`
- `double sum(double a, double b)`
- `double sum(int a, double b)`

## Coding Example

The code example below demonstrates function overloading using the same function name `sum` with different parameter lists.

```cpp
#include <iostream>
using namespace std;

int sum(int a, int b) {
    return a + b;
}

int sum(int a, int b, int c) {
    return a + b + c;
}

double sum(double a, double b) {
    return a + b;
}

double sum(int a, double b) {
    return a + b;
}

int main() {
    cout << "Sum of 5 and 10: " << sum(5, 10) << endl;
    cout << "Sum of 5, 10 and 15: " << sum(5, 10, 15) << endl;
    cout << "Sum of 5.5 and 10.3: " << sum(5.5, 10.3) << endl;
    cout << "Sum of 5 and 10.5: " << sum(5, 10.5) << endl;
    return 0;
}
```

## Important Note

- Overloaded functions must differ by parameter list; return type alone is not enough.
- This example is implemented in `funOverloading.cpp`.
