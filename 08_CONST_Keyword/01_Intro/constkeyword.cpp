#include <iostream>
using namespace std;

int main() {
    // A simple const variable
    const int x = 10;
    cout << "x = " << x << endl;

    // The following line would cause a compiler error because x is read-only
    // x = 20;

    // const can also be used for function parameters to prevent modification
    const int y = 5;
    cout << "y = " << y << endl;

    return 0;
}