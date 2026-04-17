#include <iostream>
#include <string>

using namespace std;

class Student {
public:
    string name;
    int rollNumber;
    double marks;

    void display() {
        cout << "Name      : " << name << "\n";
        cout << "Roll No.  : " << rollNumber << "\n";
        cout << "Marks     : " << marks << "\n";
    }
};

int main() {
    // Static object: created on the stack
    // It is destroyed automatically when it goes out of scope.
    Student student1;
    student1.name = "Harsh";
    student1.rollNumber = 1;
    student1.marks = 95.5;

    cout << "Static object (stack):\n";
    student1.display();

    // Dynamic object: created on the heap using new
    // Must use delete to free heap memory.
    Student *student2 = new Student();
    // student2.name = "Harshak";  // gives error as student2 is a pointer and stores an address 
    (*student2).name = " Harshak"; // works
    // student2->name = "Priya";
    student2->rollNumber = 2;
    student2->marks = 89.0;

    cout << "\nDynamic object (heap):\n";
    student2->display();

    // Free the heap memory when done
    delete student2;
    student2 = nullptr;

    return 0;
}
