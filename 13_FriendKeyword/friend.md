# Friend Class and Function in C++

Last Updated : 17 Jan, 2026

In C++, friend functions and friend classes are concepts that allow certain functions or classes to access the private and protected members of another class.

## Friend Class in C++

A friend class can access private and protected members of other classes in which it is declared as a friend.

- Remember one thing, friendship is not mutual. If class A is a friend of B, then B doesn't become a friend of A automatically.
- We can declare a friend class in C++ by using the **friend** keyword.

![](https://media.geeksforgeeks.org/wp-content/uploads/20230524122136/friend_class.png "Click to enlarge")Friend class

#include <iostream>

using namespace std;

​

class Geeks {

private:

    int private\_variable;

​

protected:

    int protected\_variable;

​

public:

    Geeks() {

        private\_variable \= 10;

        protected\_variable \= 99;

    }

​

    // friend class declaration

    friend class GFG;

};

​

// class GFG is declared as a friend

// inside class Geeks, therefore

// Class GFG can access private members

// of class Geeks.

class GFG {

public:

    void display(Geeks& t) {

        cout << "The value of Private Variable = "

             << t.private\_variable << endl;

        cout << "The value of Protected Variable = "

             << t.protected\_variable;

    }

};

​

int main() {

    Geeks g;

    GFG fri;

    fri.display(g);

    return 0;

}

**Output**

The value of Private Variable = 10
The value of Protected Variable = 99

> **Note:** We can declare friend class or function anywhere in the base class body whether its private, protected or public block. It works all the same.

## Friend Function in C++

Like friend classes, a **friend function** can be granted special access to private and protected members of a class in C++. They are not the member functions of the class but can access and manipulate the private and protected members of that class for they are declared as friends.

![](https://media.geeksforgeeks.org/wp-content/uploads/20220802105339/FriendFunctioninC-660x328.png "Click to enlarge")

A friend function can be:

1.  A global function
2.  A member function of another class

### 1\. Global Function as Friend Function

We can declare any global function as a friend function. The following example demonstrates how to declare a global function as a friend function in C++. The keyword "friend" is placed only in the function declaration of the friend function and **not** in the **function definition or call.**

**Example**

#include <iostream>

using namespace std;

​

class base {

private:

    int private\_variable;

​

protected:

    int protected\_variable;

​

public:

    base() {

        private\_variable \= 10;

        protected\_variable \= 99;

    }

    // Friend function declaration

    friend void friendFunction(base& obj);

};

​

​

// friend function definition

void friendFunction(base& obj) {

    cout << "Private Variable: "

         << obj.private\_variable << endl;

    cout << "Protected Variable: "

         << obj.protected\_variable;

}

​

int main() {

    base object1;

    friendFunction(object1);

    return 0;

}

**Output**

Private Variable: 10
Protected Variable: 99

In the above example, we have used a global function as a friend function. A friend function can be declared in any section of the class i.e. public or private or protected.

### 2\. Member Function of Another Class as Friend Function

We can also declare a member function of another class as a friend function in C++. Forward declaration of the class is needed if we want to make a member function of another class a friend inside that class.

![](https://media.geeksforgeeks.org/wp-content/uploads/20221209150256/friend_function_syntax.png "Click to enlarge")

**Example**

#include <iostream>

using namespace std;

​

// Forward Declaration needed

class base;

​

// Another class in which function is declared

class GFG {

public:

    void GFG\_Function(base& obj);

};

​

// Base class declare a frined

// function of another class

class base {

private:

    int private\_variable;

​

protected:

    int protected\_variable;

​

public:

    base() {

        private\_variable \= 10;

        protected\_variable \= 99;

    }

​

    // Friend function declaration

    friend void GFG::GFG\_Function(base&);

};

​

// Friend function definition

void GFG::GFG_Function(base& obj) {

    cout << "Private Variable: " <<

             obj.private\_variable

         << endl;

    cout << "Protected Variable: " <<

             obj.protected\_variable;

}

​

int main() {

    base object1;

    GFG object2;

    object2.GFG\_Function(object1);

​

    return 0;

}

**Output**

Private Variable: 10
Protected Variable: 99

> **Note**: The order in which we define the friend function of another class is important and should be taken care of. We always have to define both the classes before the function definition. Thats why we have used out of class member function definition.

### **Function Friendly to Multiple Classes**

#include <iostream>

using namespace std;

​

// Forward declaration

class ABC;

​

class XYZ {

    int x;

​

public:

    void set\_data(int a)

    {

      x \= a;

    }

​

    friend void max(XYZ, ABC);

};

​

class ABC {

    int y;

​

public:

    void set\_data(int a)

    {

      y \= a;

    }

​

    friend void max(XYZ, ABC);

};

​

void max(XYZ t1, ABC t2)

{

    if (t1.x \> t2.y)

        cout << t1.x;

    else

        cout << t2.y;

}

​

// Driver code

int main()

{

    ABC \_abc;

    XYZ \_xyz;

    \_xyz.set\_data(20);

    \_abc.set\_data(35);

​

    // calling friend function

    max(\_xyz, \_abc);

    return 0;

}

**Output**

35

## Advantages vs Disadvantages of Friend Functions

**Advantages**

**Disadvantages**

Access private and protected members without inheritance

Violates data hiding by exposing private members

Enable controlled data sharing between classes

Breaks encapsulation when overused

Useful for operator overloading flexibility

Do not support runtime polymorphism

Can be declared in any access section of a class

Friendship is not inherited by derived classes
