#include <iostream>
using namespace std;

int main() {
    // 1) Pointer to const data: data cannot be changed through the pointer,
    //    but the pointer can point to another address.
    const int *a = new int(10);
    // *a = 20; // ERROR: cannot modify value through pointer to const int

    int x = 20;
    a = &x; // OK: pointer itself is not constant
    cout << "a points to: " << *a << "\n";

    // 2) Const pointer to non-const data: pointer cannot change address,
    //    but the data it points to can be modified.
    int *const b = new int(30);
    // b = &x; // ERROR: cannot change a const pointer
    *b = 40; // OK: the pointed data is mutable
    cout << "b points to: " << *b << "\n";

    // 3) Const pointer to const data: neither the pointer nor the data can change.
    const int *const c = new int(50);
    // *c = 60; // ERROR: cannot modify value through pointer to const int
    // c = &x; // ERROR: cannot change a const pointer
    cout << "c points to: " << *c << "\n";

    return 0;
}
