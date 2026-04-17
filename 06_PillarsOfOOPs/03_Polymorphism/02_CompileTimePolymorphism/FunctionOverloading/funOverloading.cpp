#include <iostream>
using namespace std;

// Function overloading - sum function with different parameter types and counts

// Sum of two integers
int sum(int a, int b) {
    return a + b;
}

// Sum of three integers
int sum(int a, int b, int c) {
    return a + b + c;
}

// Sum of two doubles
double sum(double a, double b) {
    return a + b;
}

// Sum of an integer and a double
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