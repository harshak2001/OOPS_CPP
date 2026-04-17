# Destructors in C++

A destructor is a special member function of a class that is called automatically when an object is destroyed.
Destructors are used to release resources, clean up memory, and perform final tasks before an object goes out of scope.

## What is a destructor?

- A destructor has the same name as the class but is preceded by a tilde (`~`).
- It does not have a return type, not even `void`.
- It cannot take parameters.
- It is called automatically when an object is destroyed.
- Each class can have only one destructor.

```cpp
class MyClass {
public:
    ~MyClass() {
        // cleanup code
    }
};
```

## Why do we need destructors?

- To free resources acquired by the object, such as dynamic memory, file handles, or network connections.
- To avoid resource leaks and undefined behavior.
- To ensure that cleanup happens automatically when an object’s lifetime ends.
- To keep class usage safe and predictable.

## Properties of destructors

- Same name as the class, prefixed with `~`.
- No return type.
- No parameters.
- Automatically called when an object is destroyed.
- The compiler provides a default destructor if none is defined.
- A destructor can be `public`, `protected`, or `private`.
- Destructors can be declared `virtual` when polymorphic cleanup is needed.

## Why destructor cannot be `static` or `const`

- A `static` member function does not operate on a specific object instance.
  - A destructor must run for a particular object when that object is destroyed.
  - Therefore, destructors cannot be `static`.
- A `const` function promises not to modify the object.
  - During destruction, the object is being torn down and its members may be released or modified.
  - Thus, destructors cannot be `const`.

## Automatic call for static and automatic objects

For objects created with automatic storage duration, the destructor is called automatically when the object leaves scope.

```cpp
void func() {
    MyClass obj; // constructor runs here
} // obj goes out of scope, destructor runs automatically here
```

For static objects, the destructor is called automatically when the program ends.

```cpp
static MyClass globalObj;
```

- `globalObj` is destroyed when the program terminates.
- Local `static` objects are destroyed when the program ends, not when the function exits.

## Dynamic objects require manual destruction

Objects created with `new` are stored on the heap and must be destroyed explicitly using `delete`.

```cpp
MyClass *ptr = new MyClass();
// use ptr
delete ptr; // destructor is called here
```

For arrays created with `new[]`, use `delete[]`:

```cpp
MyClass *arr = new MyClass[3];
delete[] arr; // calls destructor for each element
```

If `delete` is not used, the destructor is not called and the object will leak resources.

## Summary

- Destructors clean up when objects are destroyed.
- They are automatically called for local and static objects.
- For dynamic objects, `delete` or `delete[]` must be used.
- Destructors cannot be `static` or `const` because they operate on a specific object instance that is being destroyed.
- Always define a destructor when your class manages resources that need explicit cleanup.
