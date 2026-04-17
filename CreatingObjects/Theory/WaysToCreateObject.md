# Ways to Create Objects in C++

## Static vs Dynamic Memory Allocation

- **Static allocation (stack / automatic storage)**
  - Happens when you create objects as local variables inside a function.
  - Memory is allocated automatically on the stack.
  - Lifetime is tied to the block in which the object is defined.
  - Example: `Student s;`

- **Dynamic allocation (heap)**
  - Happens when you allocate memory using `new`.
  - Memory is allocated from the heap.
  - Lifetime is controlled manually by the programmer.
  - Example: `Student *p = new Student;`

### Stack vs Heap

- **Stack**
  - Holds local variables and function call data.
  - Fast allocation and deallocation.
  - Size is limited and managed automatically.
  - Objects on the stack are destroyed automatically when the function exits.

- **Heap**
  - Used for dynamic memory allocation.
  - Larger and more flexible than the stack.
  - Allocation and deallocation are slower.
  - Programmer must explicitly free heap memory using `delete`.

### Diagram

```mermaid
flowchart TB
    Program --> Stack[Stack (automatic memory)]
    Program --> Heap[Heap (dynamic memory)]
    Stack --> Local[Local / automatic objects]
    Heap --> Dynamic[Dynamic objects via new/delete]
```

> Note: Some Markdown viewers support Mermaid diagrams. If your viewer does not render Mermaid, you can read the diagram as plain text.

## Creating a Static Object

A static object here means a normal object created without `new`, typically stored on the stack.

```cpp
Student student1; // stack-based object
student1.name = "Harsh";
student1.rollNumber = 1;
student1.marks = 95.5;
```

- This object is automatically destroyed when it goes out of scope.
- No explicit `delete` is required.

## Creating a Dynamic Object

A dynamic object is created on the heap using `new`.

```cpp
Student *student2 = new Student();
student2->name = "Priya";
student2->rollNumber = 2;
student2->marks = 89.0;

// Use the object
student2->display();

// Free the memory when done
delete student2;
student2 = nullptr;
```

### What does `new` do?

- Allocates memory from the heap.
- Calls the class constructor to initialize the object.
- Returns a pointer to the newly created object.

### What does `delete` do?

- Calls the object's destructor.
- Releases the heap memory back to the system.
- Prevents the program from leaking heap memory.

### Array allocation

```cpp
Student *group = new Student[3];
// ... use group[0], group[1], group[2]

delete[] group;
group = nullptr;
```

- Use `delete[]` for arrays allocated with `new[]`.
- Use `delete` for single objects allocated with `new`.

## Memory Leak and Garbage Collector

### Memory Leak

A memory leak occurs when heap memory is allocated but never freed.

```cpp
Student *student3 = new Student();
// forgot to call delete student3;
```

- The memory remains reserved until the program ends.
- Repeated leaks can exhaust available memory.
- In C++, memory leaks are usually caused by missing `delete` or lost pointers.

### Garbage Collector

- A garbage collector automatically reclaims unused memory.
- Standard C++ does not have a built-in garbage collector.
- C++ relies on manual deletion and RAII (Resource Acquisition Is Initialization).

## Summary

- Use **stack-based objects** for simple, short-lived objects.
- Use **heap-based objects** when you need objects to live beyond the current scope or when size is dynamic.
- Always match `new` with `delete` and `new[]` with `delete[]`.
- There is no automatic garbage collector in standard C++, so careful memory management is essential.
