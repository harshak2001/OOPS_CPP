# `const` with Pointers in C++

In C++, `const` can be used with pointers to control whether the pointer itself can change, whether the value it points to can change, or both.

## 1. `const` before `*` — constant data

When you write `const` before `*`, the value pointed to by the pointer is constant. The pointer can be changed to point somewhere else, but the data at the target cannot be modified through this pointer.

```cpp
int x = 10;
int y = 20;
const int *ptr = &x; // pointer to const int

// *ptr = 15;      // Error: cannot modify value through ptr
ptr = &y;          // OK: pointer itself can change
```

## 2. `const` after `*` — constant pointer

When `const` appears after `*`, the pointer itself is constant. That means the pointer must always point to the same address, but the data it points to can be modified.

```cpp
int x = 10;
int y = 20;
int *const ptr = &x; // const pointer to int

*ptr = 15;          // OK: data can be modified
// ptr = &y;         // Error: cannot change the pointer
```

## 3. Both before and after `*` — constant pointer to constant data

When both the pointer and the data are constant, neither the address stored by the pointer nor the data it points to can be changed.

```cpp
int x = 10;
int y = 20;
const int *const ptr = &x; // const pointer to const int

// *ptr = 15;      // Error: cannot modify value through ptr
// ptr = &y;       // Error: cannot change pointer
```

## 4. Other useful forms

- `const int *ptr` is equivalent to `int const *ptr`.
- `int const *const ptr` means the same as `const int *const ptr`.

## 5. Summary

- `const int *ptr` or `int const *ptr`
  - pointer is mutable
  - pointed value is immutable

- `int *const ptr`
  - pointer is immutable
  - pointed value is mutable

- `const int *const ptr` or `int const *const ptr`
  - pointer is immutable
  - pointed value is immutable

These forms help make pointer usage safer and more intentional by preventing unintended changes to either the referenced value or the pointer itself.
