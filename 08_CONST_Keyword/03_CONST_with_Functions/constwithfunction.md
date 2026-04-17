🔹 Const Functions in C++

🧠 Concept In C++, you can declare a member function as const to indicate that it does not modify the state of the object it is called on. This enforces read-only behavior on objects.

🔹 Syntax return_type functionName() const;

🔹 What does const mean here?

When a function is marked as const:

The object is treated as read-only You cannot modify any member variables The this pointer becomes: const ClassName\* const this;

🔹 Key Rules

✅ 1. Cannot modify member variables A const function cannot change any data members of the class.

Example: int getX() const → allowed x = 10 inside const function → not allowed

✅ 2. Can only call const functions Inside a const function, you can only call other const member functions. Calling a non-const function will give an error.

✅ 3. Const ensures object safety

Prevents accidental modification Makes code predictable Improves readability and maintainability

✅ 4. Const objects can only call const functions

If an object is declared as const, it can only call const member functions.

Example: const object → can call get() const object → cannot call set()

🔹 Mutable Keyword

🧠 Concept The mutable keyword allows a member variable to be modified even inside a const function.

✅ Usage

Debugging Caching values Logging

⚠️ Not recommended for regular use because it breaks const correctness.

🔹 Why use const functions?

Enforces data protection Helps in writing bug-free code Important for **API** design Allows usage with const objects and references

🔹 Quick Summary ⚡

const function → cannot modify object state Cannot change member variables Can only call other const functions mutable allows exception (use carefully) const objects → can call only const functions
