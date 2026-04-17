# Diamond Problem in C++

The diamond problem occurs when one class inherits from two classes that both inherit from the same base class.
This creates a diamond-shaped inheritance structure.

```
      A
     / \
    B   C
     \ /
      D
```

- `A` is the common base class.
- `B` and `C` both inherit from `A`.
- `D` inherits from both `B` and `C`.

## Why it is a problem

- `D` receives two copies of `A`'s members: one through `B` and one through `C`.
- This can cause ambiguity and duplicate data.
- For example, calling a method or accessing a member defined in `A` is unclear: should it use the copy from `B` or from `C`?

## How C++ solves it

- One solution is to use scope resolution to select the desired base path.
  - Example: `obj.B::show()` or `obj.C::show()`.
  - This resolves ambiguity but does not remove the duplicate base subobjects.

- A better solution is to use `virtual` inheritance.
  - Virtual inheritance ensures that there is only one shared instance of the common base class (`A`) in `D`.
  - Then `obj.show()` becomes unambiguous and all derived classes share the same `A` data.
