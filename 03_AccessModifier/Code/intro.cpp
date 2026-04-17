#include <iostream>
using namespace std;

// Creation of class with access specifiers
class Student {
public:
    // public members can be accessed from outside the class
    string name;

    int getRollNo() {
        return rollNo; // private member is accessed inside the class
    }

    void setRollNo(int rollNo) {
        this->rollNo = rollNo;
    }

    void setMarks(int m) {
        marks = m; // protected member is accessed inside the class
    }

    void print() {
        cout << "Name     : " << name << endl;
        cout << "Roll No. : " << rollNo << endl;
        cout << "Marks    : " << marks << endl;
    }

private:
    // private members are only accessible inside this class
    int rollNo;

protected:
    // protected members are accessible in this class and derived classes
    int marks;
};

// Derived class to demonstrate protected access
class ClassMonitor : public Student {
public:
    void setMonitorMarks(int m) {
        marks = m; // allowed because marks is protected
    }

    void showMonitorInfo() {
        cout << "Monitor name : " << name << endl; // public access
        cout << "Monitor marks: " << marks << endl; // protected access
    }
};

int main() {
    Student s1;

    // public member access is allowed
    s1.name = "Harshak";

    // private member cannot be accessed directly from outside
    // s1.rollNo = 12; // error: rollNo is private

    // protected member cannot be accessed directly from outside
    // s1.marks = 90; // error: marks is protected

    // use public methods to access private/protected data safely
    s1.setRollNo(12);
    s1.setMarks(90);

    cout << "Using Student object:\n";
    s1.print();

    ClassMonitor monitor;
    monitor.name = "Priya"; // public
    monitor.setRollNo(5);
    monitor.setMonitorMarks(95); // protected member accessed in derived class

    cout << "\nUsing ClassMonitor object:\n";
    monitor.showMonitorInfo();

    return 0;
}
