# 📘 Shallow Copy vs Deep Copy (C++)

## 🧠 What is Copying an Object?

In C++, copying an object means creating a **new object** from an existing one.

This can happen in:

- Copy constructor → `Class obj2(obj1);`
- Assignment → `obj2 = obj1;`

Depending on how memory is handled, copying can be:

- **Shallow Copy**
- **Deep Copy**

## ⚠️ Why Do We Need Different Types of Copy?

When objects contain:

- **Primitive data (int, float, etc.) → simple copy works**
- **Dynamic memory (heap allocation using pointers) → special handling required**

👉 Problem arises when objects share the **same memory reference**.

# 🔹 Shallow Copy

## 📌 What is Shallow Copy?

A **shallow copy** copies:

- All variable values **as-is**
- Including **memory addresses (pointers)**

👉 Both objects end up pointing to the **same memory location**

## ⚙️ How It Works

class A {  
public:  
 int\* data;  
};

A obj1;  
obj1.data = new int(10);

A obj2 = obj1; // Shallow Copy

📌 Now:

- `obj1.data` and `obj2.data` → same address

## ❗ Problems with Shallow Copy

### 1\. Shared Memory Issue

- Changing one object affects the other

\*obj2.data = 20;  
// obj1.data also becomes 20 ❌

### 2\. Dangling Pointer / Double Free ❌

delete obj1.data;

Now:

- `obj2.data` → points to **freed memory** (invalid reference)

👉 Accessing it → **undefined behavior / crash**

### 3\. Double Deletion 🚨

delete obj2.data; // already deleted ❌

👉 Causes:

- Program crash
- Memory corruption

## ✅ When is Shallow Copy Safe?

- When **no dynamic memory (heap)** is used
- Only **stack variables**

# 🔹 Deep Copy

## 📌 What is Deep Copy?

A **deep copy**:

- Copies actual values
- Allocates **new memory separately**
- Copies data into that new memory

👉 Each object has its **own independent memory**

## ⚙️ How It Works

class A {  
public:  
 int\* data;

    // Deep Copy Constructor
    A(const A& obj) {
        data = new int;
        \*data = \*(obj.data);
    }

};

## ✅ Behavior

A obj1;  
obj1.data = new int(10);

A obj2 = obj1; // Deep Copy

Now:

- `obj1.data` ≠ `obj2.data`
- Values are same, memory is different

## 🎯 Benefits of Deep Copy

✔ No shared memory  
✔ No accidental modification  
✔ Safe deletion  
✔ No dangling pointers

# 💥 Problem Deep Copy Solves

Issue

Shallow Copy

Deep Copy

Shared memory

❌ Yes

✅ No

Unexpected changes

❌ Yes

✅ No

Dangling pointer

❌ Possible

✅ Avoided

Double delete

❌ Possible

✅ Safe

# 🧨 Deletion & Memory Safety

## ⚠️ Problem Scenario

A obj1;  
obj1.data = new int(10);

A obj2 = obj1; // shallow copy

delete obj1.data;

Now:

- `obj2.data` → **invalid reference (dangling pointer)**

👉 Accessing it:

cout << \*obj2.data; // ❌ crash / garbage

## ✅ Solution

Use **Deep Copy**:

- Each object manages its own memory
- Safe deletion

# 🔧 Rule of 3 (Very Important)

If your class uses **dynamic memory**, you must define:

1.  **Copy Constructor**
2.  **Copy Assignment Operator**
3.  **Destructor**

~A() {  
 delete data;  
}

# 🧠 Key Differences

Feature

Shallow Copy

Deep Copy

Memory

Shared

Separate

Pointer Copy

Address copied

New memory allocated

Safety

❌ Unsafe

✅ Safe

Performance

Faster

Slightly slower

Use Case

Simple objects

Objects with heap memory

# 🚀 When to Use What?

### ✅ Use Shallow Copy:

- No pointers
- No dynamic allocation

### ✅ Use Deep Copy:

- Using `new`, `malloc`, etc.
- Managing resources (files, memory, buffers)

# 🧩 Real-Life Analogy

### 🧾 Shallow Copy:

Photocopy of a **key**  
👉 Both open the **same locker**

### 🏦 Deep Copy:

Duplicate **locker with same items**  
👉 Independent access

# ✨ Final Takeaway

- Shallow copy = **same reference → risky**
- Deep copy = **new memory → safe**
- Always use **deep copy when dealing with dynamic memory**
