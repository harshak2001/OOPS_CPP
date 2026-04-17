🔹 Initialization List in C++ 🧠 What is Initialization List?

An Initialization List is a way to initialize member variables of a class before the constructor body executes.

It is written after the constructor signature and before the constructor body, using a colon (:).

🔹 Syntax

Constructor(parameters) : member1(value1), member2(value2) { // constructor body }

🔹 Example

class Example { int x; int y;

public: Example(int a, int b) : x(a), y(b) { // body } };

🔹 Why do we need Initialization List? ✅ 1. Performance Optimization Without initialization list: Variables are first default initialized Then assigned values inside constructor With initialization list: Variables are directly initialized

👉 This avoids extra work → more efficient

✅ 2. Required for const members

const variables must be initialized using initialization list

class Example { const int x;

public: Example(int val) : x(val) {} };

❌ This will **NOT** work: x = val; // error

✅ 3. Required for reference members

References must be initialized at the time of declaration

class Example { int& ref;

public: Example(int& r) : ref(r) {} };

✅ 4. Required for objects (composition)

If a class contains another class object, it must be initialized using initialization list

class A { public: A(int x) {} };

class B { A obj;

public: B(int x) : obj(x) {} };

🔹 How it works internally?

Order of execution:

Member variables are initialized in the order they are declared in class (**NOT** order in list) Then constructor body runs

⚠️ Important: Even if you write: : y(b), x(a)

If declared as: int x; int y;

👉 x will be initialized first, then y

🔹 Real Life Analogy

Think of building a house 🏠

Initialization list = laying foundation while building Constructor body = decorating after construction

👉 You don’t first build empty rooms and then rebuild walls 👉 You construct them correctly from the start

🔹 Without Initialization List vs With

Without:

Example(int a) { x = a; }

Steps:

x default initialized x assigned value

With:

Example(int a) : x(a) {}

Steps:

x directly initialized

👉 Faster and cleaner

🔹 Best Practices Always prefer initialization list Mandatory for: const members references objects Keep order same as declaration (avoid confusion) 🔹 Quick Summary ⚡ Initialization list initializes members before constructor body Improves performance Required for const, reference, and object members Execution order depends on declaration, not list order Cleaner and more efficient code
