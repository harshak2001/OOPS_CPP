#include <iostream>
#include <string>

using namespace std;

// Class syntax and structure
// --------------------------
// class ClassName {
// Access Specifier:
//     // data members (attributes)
//     // member functions (methods)
// };

class Student {
public: //Access Specifier

    // Data members
    string name;
    int rollNumber;
    double marks;

    // Member function
    void display() {
        cout << "Name       : " << name << "\n";
        cout << "Roll No.   : " << rollNumber << "\n";
        cout << "Marks      : " << marks << "\n";
    }
};

int main() {
    // Creating an object of the class
    Student student1;

    // Setting values for the object's data members
    student1.name = "Harshak";
    student1.rollNumber = 1;
    student1.marks = 95.5;

    cout << "Student 1 details:\n";
    student1.display();

    // Another object
    Student student2;
    student2.name = "Priya";
    student2.rollNumber = 2;
    student2.marks = 89.0;

    cout << "\nStudent 2 details:\n";
    student2.display();

    return 0;
}
