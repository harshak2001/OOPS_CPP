# Encapsulation in OOP

Encapsulation is one of the four main pillars of object-oriented programming.
It means bundling data members and member functions inside a single unit, usually a class.
Encapsulation also hides internal details from outside code, exposing only what is necessary.

## What is encapsulation?

- Encapsulation is the practice of keeping data and behavior together inside a class.
- It restricts direct access to object internals by using access specifiers like `private`, `protected`, and `public`.
- The object controls how its data is accessed and modified through methods.
- This creates a clear separation between an object’s interface and its implementation.

## Why do we need encapsulation?

- To protect internal data from being changed incorrectly.
- To prevent external code from depending on internal implementation details.
- To make code easier to maintain and evolve.
- To provide a stable interface while allowing implementation changes behind the scenes.
- To improve security by hiding sensitive information.

## Real-world example

Imagine a television remote control:

- The remote has buttons like `power`, `volume`, and `channel`.
- A person uses the buttons without needing to know how the remote sends signals to the TV.
- The remote hides the internal electronics, battery, and circuit design.
- This is encapsulation: visible controls form the interface, while complex details are hidden.

## Example in technology

In software, a bank account class is a common example:

```cpp
class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance) {
        if (initialBalance < 0) initialBalance = 0;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false;
    }

    double getBalance() const {
        return balance;
    }
};
```

- `balance` is `private`, so outside code cannot change it directly.
- The class provides controlled access through `deposit`, `withdraw`, and `getBalance`.
- The class ensures the balance never becomes invalid.

## What is perfect encapsulation?

- Perfect encapsulation means the class hides as much internal detail as possible while still providing the required public behavior.
- It means exposing only what is needed and keeping everything else private.
- Perfect encapsulation prevents outside code from relying on internal structure, making the class easier to update without breaking users.
- In practice, perfect encapsulation is a goal rather than an absolute state.

## Advantages of encapsulation

- Improved data protection and integrity.
- Reduced coupling between classes.
- Better control over how data changes.
- Easier debugging and testing.
- Clearer API for class users.
- Ability to change implementation without changing external code.
