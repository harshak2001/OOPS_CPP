# Multilevel Inheritance

Multilevel inheritance occurs when a class is derived from a derived class.

```
BaseClass
   |
IntermediateClass
   |
DerivedClass
```

Example chain:
- `Animal` → `Mammal` → `Dog`

The most derived class inherits members from all classes above it.
