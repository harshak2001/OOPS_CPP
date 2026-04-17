#include <iostream>
using namespace std;

// Non-virtual inheritance example: ambiguity is resolved with scope resolution.
class A1 {
public:
    void show() const {
        cout << "A1::show()" << endl;
    }
};

class B1 : public A1 {
};

class C1 : public A1 {
};

class D1 : public B1, public C1 {
};

// Virtual inheritance example: shared base class instance.
class A2 {
public:
    void show() const {
        cout << "A2::show()" << endl;
    }
};

class B2 : virtual public A2 {
};

class C2 : virtual public A2 {
};

class D2 : public B2, public C2 {
};

int main() {
    cout << "Scope-resolution example:" << endl;
    D1 obj1;
    obj1.B1::show(); // use B1's A1 subobject
    obj1.C1::show(); // use C1's A1 subobject

    cout << endl;
    cout << "Virtual inheritance example:" << endl;
    D2 obj2;
    obj2.show(); // unambiguous because A2 is shared virtually

    return 0;
}
