#include <iostream>
using namespace std;

class Printer {
public:
    void print() const {
        cout << "Printing document" << endl;
    }
};

class Scanner {
public:
    void scan() const {
        cout << "Scanning document" << endl;
    }
};

class MultiFunctionPrinter : public Printer, public Scanner {
};

int main() {
    MultiFunctionPrinter device;
    device.print();
    device.scan();
    return 0;
}
