# Inheritance in C++

## Overview

Inheritance is a mechanism that allows a class to acquire properties and methods from another class, promoting code reuse and establishing a hierarchical relationship.

## Real-World Examples

### Example 1: Vehicle Hierarchy

```
┌─────────────┐
│   Vehicle   │ (Base Class)
├─────────────┤
│ - speed     │
│ - color     │
├─────────────┤
│ + start()   │
│ + stop()    │
└──────┬──────┘
    │
    ├─────────────────┬─────────────────┐
    │                 │                 │
   ┌───▼───┐         ┌───▼───┐        ┌───▼────┐
   │  Car  │         │ Bike  │        │ Truck  │
   └───────┘         └───────┘        └────────┘
```

### Example 2: Employee Structure

- **Employee** (Base) → **Manager**, **Developer**, **Designer** (Derived)

## Access Specifiers

| Specifier     | Base Class | Derived Class | Outside Class |
| ------------- | :--------: | :-----------: | :-----------: |
| **public**    |     ✓      |       ✓       |       ✓       |
| **protected** |     ✓      |       ✓       |       ✗       |
| **private**   |     ✓      |       ✗       |       ✗       |

## Inheritance Access Conversion

When a class derives from a base class, the inherited member access can change depending on the inheritance specifier.
The table below shows how `public` and `protected` members of the base class appear in the derived class.
Private base members are not accessible to derived classes, so they are effectively `NA`.

| Base member access | `public` inheritance | `protected` inheritance | `private` inheritance |
| ------------------ | :------------------: | :---------------------: | :-------------------: |
| `public`           |       `public`       |       `protected`       |       `private`       |
| `protected`        |     `protected`      |       `protected`       |       `private`       |
| `private`          |         `NA`         |          `NA`           |         `NA`          |

## Types of Inheritance

- Single Inheritance
- Multiple Inheritance
- Multilevel Inheritance
- Hierarchical Inheritance
- Hybrid Inheritance
- Multipath Inheritance

## Example Code

```cpp
class Vehicle {
protected:
    int speed;
public:
    void start() { /* ... */ }
};

class Car : public Vehicle {
public:
    void honk() { /* ... */ }
};
```
