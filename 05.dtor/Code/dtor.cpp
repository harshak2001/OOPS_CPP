#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    string name;
    int rollNo;
    int marks;

    void print() {
        cout << "Name     : " << name << endl;
        cout << "Roll No. : " << rollNo << endl;
        cout << "Marks    : " << marks << endl;
    }

    // Default constructor
    Student() {
        cout << "Default constructor called" << endl;
        name = "Unknown";
        rollNo = 0;
        marks = 0;
    }

    // Parameterised constructor
    Student(string name, int rollNo, int marks) {
        cout << "Parameterized constructor called for " << name << endl;
        this->name = name;
        this->rollNo = rollNo;
        this->marks = marks;
    }

    // Destructor
    // A destructor is called automatically when an object is destroyed.
    // It cannot be static because it must run for a specific object instance.
    // It cannot be const because destruction may modify internal state while releasing resources.
    ~Student() {
        cout << "Destructor called for " << this->name << endl;
    }
};

int main() {
    cout << "--- Automatic (stack) object example ---" << endl;
    Student s1("Automatic", 1, 99);
    s1.print();
    cout << endl;

    {
        cout << "--- Block scope object example ---" << endl;
        Student s3("BlockScope", 3, 70);
        s3.print();
        cout << "Block is ending. s3 will be destroyed automatically." << endl;
    }
    cout << endl;

    cout << "--- Dynamic (heap) object example ---" << endl;
    Student* s2 = new Student("Dynamic", 2, 85);
    s2->print();
    cout << "For dynamic objects, destructor is not called until delete is used." << endl;
    delete s2; // Destructor called manually by delete for dynamic objects.
    cout << endl;

    cout << "--- Static storage object example ---" << endl;
    static Student s4("StaticStorage", 4, 60);
    s4.print();
    cout << "Static object will be destroyed automatically when the program ends." << endl;
    cout << endl;

    cout << "Exiting main. Remaining objects will be destroyed in reverse creation order." << endl;
    return 0;
}
