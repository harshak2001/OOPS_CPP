#include <iostream>
using namespace std;

class BankAccount {
private:
    // The balance is private so outside code cannot modify it directly.
    // This protects the account from invalid changes.
    int balance;

public:
    // Constructor initializes balance and prevents negative starting values.
    BankAccount(int balance) {
        if (balance < 0) {
            this->balance = 0;
        } else {
            this->balance = balance;
        }
    }

    // deposit allows controlled modification of the balance.
    // It rejects negative amounts, so the account cannot lose money this way.
    void deposit(int amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // withdraw also validates the request before changing the balance.
    // The method returns whether the withdrawal succeeded.
    bool withdraw(int amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // getBalance exposes only the current balance value.
    // External code can read the balance but cannot change it directly.
    int getBalance() const {
        return balance;
    }
};

int main() {
    // Create a BankAccount object with automatic storage.
    BankAccount savings(1000);

    // The user reads the balance through the public interface.
    cout << "Initial balance: " << savings.getBalance() << endl; // 1000

    // Withdraw money using the encapsulated withdraw method.
    if (savings.withdraw(200)) {
        cout << "After withdrawal: " << savings.getBalance() << endl; // 800
    } else {
        cout << "Withdrawal failed." << endl;
    }

    // Deposit money using the encapsulated deposit method.
    savings.deposit(100);
    cout << "After deposit: " << savings.getBalance() << endl; // 900

    // Attempting to set balance directly would be impossible from here.
    // Encapsulation ensures all changes go through controlled methods.

    return 0;
}
