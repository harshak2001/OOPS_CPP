#include<iostream>
#include <string>
using namespace std;

class Student{

    public:
    string name;
    int rollNo;
    int marks;

    void print() {
        cout << "Name     : " << name << endl;
        cout << "Roll No. : " << rollNo << endl;
        cout << "Marks    : " << marks << endl;
    }

    Student(){
        cout<<"Default constructor called"<<endl;
    }

    Student(string name){
        cout<<"Parameterised ctor called"<<endl;
        this->name = name;
        this->rollNo = -1;
        this->marks = -1;

    }

    Student(string name,int rollNo){
        cout<<"Parameterised ctor called"<<endl;
        this->name = name;
        this->rollNo = rollNo;
        this->marks = -1;
    }

    Student(string name,int rollNo,int marks){
        cout<<"Parameterised ctor called"<<endl;
        this->name = name;
        this->rollNo = rollNo;
        this->marks = marks;
    }
    Student(const Student &x){
        this->name = x.name;
        this->rollNo = x.rollNo;
        this->marks = x.marks;
    }
};


int main(){
    //static
    Student s1("Harshak",1,99);
    s1.print();

    //dynamic
    // Student* s2 = new Student("Aditya");
    // s2->print();

    // Student s3(s1);
    Student s3 = s1;
    s3.print();

    return 0;
}