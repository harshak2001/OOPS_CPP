# Abstraction in Object-Oriented Programming

Abstraction is the concept of hiding the internal implementation details of a class and exposing only the essential features to the outside world.

## What is Abstraction?

In OOP, abstraction helps you model real-world systems by focusing on what an object does rather than how it does it.
A class exposes a simple interface while keeping complex code hidden inside its implementation.

## Real-world examples

- **ATM machine**: Users interact with the keypad and screen, but they do not see the internal banking system logic.
- **Car dashboard**: Drivers use the steering wheel, pedals, and buttons without knowing how the engine, transmission, or electronics work.
- **Television remote**: The remote sends commands like "volume up" and "change channel" without showing the infrared signal details.
- **Smartphone app**: Users tap buttons and gestures while the app handles network requests, data storage, and rendering.

## Abstraction in C++

In C++, abstraction is often implemented using:

- **Classes** to group data and behavior.
- **Access specifiers** like `private` and `public` to hide internal data.
- **Abstract classes** and **pure virtual functions** to define an interface without a full implementation.

An abstract class cannot be instantiated directly. It defines a contract that derived classes must fulfill.

## Example

A simple abstract class could represent a generic device with methods such as `turnOn()` and `turnOff()`.
Derived classes like `TV` or `Radio` provide the actual implementation, while the main program uses the device interface.

This lets the user work with different devices in the same way, without needing to know the implementation details of each one.

## Summary

Abstraction improves code modularity and maintainability by:

- hiding complexity
- exposing only the necessary interface
- letting different implementations share a common behavior
- making the code easier to understand and change
