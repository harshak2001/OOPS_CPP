# Access Specifiers in C++

Access specifiers control which parts of a class can be accessed from outside the class.
They are used to implement encapsulation and protect object data from unintended use.

## Main access specifiers

- `public` : Members are accessible from anywhere the object is visible.
- `protected` : Members are accessible inside the class itself and in derived classes.
- `private` : Members are accessible only within the class itself.

## Why do we need access specifiers?

Access specifiers are important because they:

- protect internal data and implementation details
- prevent external code from changing an object in invalid ways
- make class interfaces clearer and safer
- support encapsulation and maintainability
- allow controlled extension in derived classes

## Example

```cpp
class Example {
public:
    int publicValue;   // accessible from anywhere

protected:
    int protectedValue; // accessible in Example and derived classes

private:
    int privateValue;  // accessible only inside Example
};
```

## Comparison table

| Specifier   | Accessible from same class | Accessible from derived class | Accessible from outside class | Typical use case      |
| ----------- | -------------------------- | ----------------------------- | ----------------------------- | --------------------- |
| `public`    | Yes                        | Yes                           | Yes                           | Public interface      |
| `protected` | Yes                        | Yes                           | No                            | Base-class extension  |
| `private`   | Yes                        | No                            | No                            | Internal data/helpers |

## Notes

- In a `class`, members are `private` by default if no specifier is given.
- In a `struct`, members are `public` by default.
- Use `private` for core data and helper functions.
- Use `public` for methods and data that are part of the class interface.
- Use `protected` when derived classes need access, but external code should not.
