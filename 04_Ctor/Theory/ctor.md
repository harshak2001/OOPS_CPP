# Constructors in C++

A constructor is a special member function of a class that is called automatically when an object is created.
Constructors initialize object state and prepare the object for use.

## What is a constructor?

- A constructor has the same name as the class.
- It does not have a return type, not even `void`.
- It is called automatically when an object is created.
- It can take parameters, or it can take none.
- Constructors help set initial values for data members.

## Properties of constructors

- Same name as the class.
- No return type.
- Can be `public`, `private`, or `protected` depending on how objects should be created.
- Can be overloaded: multiple constructors with different parameter lists.
- Can call other constructors indirectly through constructor delegation (C++11+).
- Automatically invoked during object creation.

## Types of constructors

### 1. Default constructor

A default constructor is a constructor that can be called without any arguments.
It may be provided by the compiler if no constructors are defined.

```cpp
class Point {
public:
    int x;
    int y;
    Point() {
        x = 0;
        y = 0;
    }
};
```

This can be used as:

```cpp
Point p; // calls default constructor
```

### 2. Parametrized constructor

A parametrized constructor accepts one or more arguments to initialize object data.

```cpp
class Point {
public:
    int x;
    int y;
    Point(int xValue, int yValue) {
        x = xValue;
        y = yValue;
    }
};
```

Use it like:

```cpp
Point p(10, 20);
```

### 3. Copy constructor

A copy constructor creates a new object as a copy of an existing object.

```cpp
class Point {
public:
    int x;
    int y;
    Point(const Point &other) {
        x = other.x;
        y = other.y;
    }
};
```

A copy constructor is used when:

- a new object is initialized from an existing object
- an object is passed by value to a function
- an object is returned by value from a function

## Why pass value to copy constructor as reference?

A copy constructor is usually declared as `ClassName(const ClassName &other)`.

Reasons:

- Passing by reference avoids an infinite recursion loop.
  - If the parameter were passed by value, the copy constructor would need to copy the argument, which would call the copy constructor again.
- References avoid creating a temporary copy of the object.
- It is more efficient because only an alias is passed, not a full object.
- `const` protects the source object from modification inside the constructor.

## Ways to use the copy constructor

### 1. Direct initialization

```cpp
Point p1(5, 10);
Point p2(p1); // copy constructor is called
```

### 2. Copy initialization

```cpp
Point p3 = p1; // copy constructor is called
```

### 3. Passing by value to a function

```cpp
void printPoint(Point p) {
    cout << p.x << ", " << p.y << endl;
}
printPoint(p1); // copy constructor is called when p is created
```

### 4. Returning by value from a function

```cpp
Point createPoint() {
    Point p(1, 2);
    return p; // copy constructor may be used here
}
```

## Summary

- Constructors initialize objects and are automatically called.
- Default constructors take no arguments.
- Parametrized constructors accept values for initialization.
- Copy constructors create a new object from an existing one.
- Use `const ClassName &` for copy constructors to avoid recursion and extra copying.
- Copy constructors are used during direct initialization, copy initialization, pass-by-value, and return-by-value.
