# Hybrid Inheritance

Hybrid inheritance is a combination of two or more types of inheritance.

Example structure:
- `Engine` → `Vehicle` (single/multilevel inheritance)
- `SmartCar` inherits from both `Vehicle` and `Stereo` (multiple inheritance)

```
Engine
  |
Vehicle   Stereo
   \      /
    SmartCar
```

Hybrid inheritance mixes different inheritance patterns in one design.
