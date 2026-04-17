# `const` Keyword in C++

## What is `const`?

`const` is a keyword in C++ that makes a variable read-only after initialization. It is like a promise: once you assign a value to a `const` variable, you promise not to change it later.

## Can the promise be broken?

In normal C++ code, the promise cannot be broken. The compiler enforces `const` and prevents modifications. However, using unsafe techniques like type casting (`const_cast`) or manipulating memory directly can break that promise, so it should be avoided.

## Syntax

```cpp
const int x = 10;
const float pi = 3.14f;
const char* name = "Hello";
```

Examples:
- `const int x = 5;`
- `const double rate = 9.81;`
- `const string title = "C++";`

## Why do we need `const`?

- It protects values from accidental modification.
- It documents intent: this value should not change.
- It helps the compiler and other developers understand code behavior.
- It is especially useful for function parameters and return values where immutability matters.

## Compiler behavior and storage

When a variable is declared as `const`, the compiler may store it in a separate area of memory reserved for constant values. That means the compiler can assume the value will not change and may optimize access accordingly.

Because the value is fixed, the compiler does not need to treat it like a regular writable variable. This can reduce the runtime overhead of checking or loading a variable again and again.

## `lvalue` and `rvalue`

- `lvalue`: An expression that refers to an object with a persistent location in memory. It can appear on the left side of an assignment.
  - Example: `x`, `arr[0]`, `myObject.value`
- `rvalue`: A temporary value or literal that does not have a stable memory address and usually cannot appear on the left side of an assignment.
  - Example: `5`, `x + 2`, `func()`

### `const` with lvalues and rvalues

- A `const` variable is still an `lvalue` because it has a memory location.
- A literal like `10` is an `rvalue`.
- You cannot assign to a `const` lvalue, for example:

```cpp
const int x = 10;
x = 20; // error
```

## Summary

Use `const` to make a promise that a value should not change. It improves code safety, helps the compiler optimize, and clearly signals intent. `lvalues` are named memory locations, while `rvalues` are temporary results.
