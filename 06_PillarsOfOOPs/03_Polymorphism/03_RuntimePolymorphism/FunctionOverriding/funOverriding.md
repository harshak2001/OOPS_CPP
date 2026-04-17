# Runtime Polymorphism: Function Overriding

## What is Runtime Polymorphism?
Runtime polymorphism means the program decides which function to call while the program is running, not at compile time.
In C++, this is usually achieved through inheritance, pointers or references to base class, and virtual functions.

## What is Method Overriding?
Method overriding (also called function overriding) happens when:
- a derived class defines a function with the same name and signature as a base class function,
- the base function is marked as `virtual`, and
- a base class pointer or reference refers to a derived class object.

The derived version replaces the base version at runtime.

### Example
```cpp
class Base {
public:
    virtual void show() {
        std::cout << "Base show()\n";
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived show()\n";
    }
};

Base* ptr = new Derived();
ptr->show(); // Calls Derived::show() because show() is virtual
```

## Why is this called "method overriding"?
- "Override" means the derived class gives its own implementation of a base class method.
- The base method still exists, but the derived method takes precedence for derived objects.
- The signature must match exactly.

## Upcasting and Downcasting

### Upcasting
- Converting a derived class pointer/reference to a base class pointer/reference.
- It is safe and implicit.
- Example: `Derived* d = new Derived(); Base* b = d;`
- Useful because it allows treating a derived object like its base type.

### Downcasting
- Converting a base class pointer/reference back to a derived class pointer/reference.
- It is not always safe and usually requires `dynamic_cast`.
- Example:
```cpp
Base* b = new Derived();
Derived* d = dynamic_cast<Derived*>(b);
if (d) {
    d->show();
}
```
- If `b` does not actually point to a `Derived`, `dynamic_cast` returns `nullptr`.

### Variations
- `Base* b = new Derived();` → upcast from `Derived*` to `Base*`
- `Derived* d = dynamic_cast<Derived*>(b);` → downcast from `Base*` to `Derived*`
- `static_cast<Derived*>(b)` can be used if you are sure the object is actually `Derived`, but it is less safe.

## Simple trick to remember
- Override = same function name + same signature, but in the child class.
- Upcast = go up the inheritance tree (child → parent).
- Downcast = go down the inheritance tree (parent → child).
- If you want runtime behavior, `virtual` in the base class is the key.

## Quick glance at virtual functions
- `virtual` tells C++ to use runtime binding instead of compile-time binding.
- When a base class pointer/reference refers to a derived object, the derived `virtual` function is called.
- Without `virtual`, the base class version is called even if the object is derived.
- Use `override` in the derived class to make the intent explicit and catch signature mistakes.

### Quick rule
- Base function: `virtual void show();`
- Derived function: `void show() override;`

---

This gives you a compact explanation of runtime polymorphism, function/method overriding, upcasting, downcasting, and virtual functions.
