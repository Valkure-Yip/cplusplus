# Cpp learning notes

## VSCode env setup

[Configure VS Code for Clang/LLVM on macOS](https://code.visualstudio.com/docs/cpp/config-clang-mac)

Run build task: command+ shift + B



[C++ Tutorial](https://www.w3schools.com/CPP/default.asp)





## Basics

```cpp
#include <iostream>
using namespace std;

int main() {
  cout << "Hello World!";
  return 0;
}
```

`#include <iostream>` is a header file library: input and output objects, such as cout.

using namespace std means that we can use names for objects and variables from the standard library.ß

The using namespace std line can be omitted and replaced with the std keyword, followed by the :: operator for some objects:

```cpp
std::cout << "Hello World!";
```

## Variables

- int - stores integers (whole numbers), without decimals, such as 123 or -123
- double - stores floating point numbers, with decimals, such as 19.99 or -19.99
- char - stores single characters, such as 'a' or 'B'. Char values are surrounded by single quotes
- string - stores text, such as "Hello World". String values are surrounded by double quotes
- bool - stores values with two states: true or false

### constants

```cpp
const int myNum = 15;  // myNum will always be 15
myNum = 10;  // error: assignment of read-only variable 'myNum'
```



## Data Types

**double** has 2x more precision then **float**.

**float** is a 32 bit (4 bytes) IEEE 754 single precision Floating Point Number1 bit for the sign, (8 bits for the exponent, and 23* for the value), i.e. float has 7 decimal digits of precision.

**double** is a 64 bit (8 bytes) IEEE 754 double precision Floating Point Number (1 bit for the sign, 11 bits for the exponent, and 52* bits for the value), i.e. double has 15 decimal digits of precision.

**bool** can only take the values `true` or `false`. When the value is returned, `true` = `1` and `false` = `0`.

**char** store a **single** character. The character must be surrounded by **single quotes**, like 'A' or 'c':

```cpp
char a = 'B';
char b = 65 // ASCII
```

**string** not a built-in type, need to  `#include <string>`, **double quote**

```cpp
// Include the string library
#include <string>

// Create a string variable
string greeting = "Hello";
```



[C++ Data Types](https://www.tutorialspoint.com/cplusplus/cpp_data_types.htm)

|          Type          | Typical Bit Width |          Typical Range          |
| :--------------------: | :---------------: | :-----------------------------: |
|          char          |       1byte       |     -127 to 127 or 0 to 255     |
|     unsigned char      |       1byte       |            0 to 255             |
|      signed char       |       1byte       |           -127 to 127           |
|          int           |      4bytes       |    -2147483648 to 2147483647    |
|      unsigned int      |      4bytes       |         0 to 4294967295         |
|       signed int       |      4bytes       |    -2147483648 to 2147483647    |
|       short int        |      2bytes       |         -32768 to 32767         |
|   unsigned short int   |      2bytes       |           0 to 65,535           |
|    signed short int    |      2bytes       |         -32768 to 32767         |
|        long int        |      8bytes       | -2,147,483,648 to 2,147,483,647 |
|    signed long int     |      8bytes       |        same as long int         |
|   unsigned long int    |      8bytes       |       0 to 4,294,967,295        |
|     long long int      |      8bytes       |       -(2^63) to (2^63)-1       |
| unsigned long long int |      8bytes       | 0 to 18,446,744,073,709,551,615 |
|         float          |      4bytes       |                                 |
|         double         |      8bytes       |                                 |
|      long double       |      12bytes      |                                 |
|        wchar_t         |   2 or 4 bytes    |        1 wide character         |



## Math

### native methods:

```cpp
min(x,y);
max(x,y);
```

### `<cmath>`

```cpp
#include <cmath>

cout << sqrt(64)
```



| Function     | Description                                                  |
| :----------- | :----------------------------------------------------------- |
| abs(x)       | Returns the absolute value of x                              |
| acos(x)      | Returns the arccosine of x                                   |
| asin(x)      | Returns the arcsine of x                                     |
| atan(x)      | Returns the arctangent of x                                  |
| cbrt(x)      | Returns the cube root of x                                   |
| ceil(x)      | Returns the value of x rounded up to its nearest integer     |
| cos(x)       | Returns the cosine of x                                      |
| cosh(x)      | Returns the hyperbolic cosine of x                           |
| exp(x)       | Returns the value of Ex                                      |
| expm1(x)     | Returns ex -1                                                |
| fabs(x)      | Returns the absolute value of a floating x                   |
| fdim(x, y)   | Returns the positive difference between x and y              |
| floor(x)     | Returns the value of x rounded down to its nearest integer   |
| hypot(x, y)  | Returns sqrt(x2 +y2) without intermediate overflow or underflow |
| fma(x, y, z) | Returns x*y+z without losing precision                       |
| fmax(x, y)   | Returns the highest value of a floating x and y              |
| fmin(x, y)   | Returns the lowest value of a floating x and y               |
| fmod(x, y)   | Returns the floating point remainder of x/y                  |
| pow(x, y)    | Returns the value of x to the power of y                     |
| sin(x)       | Returns the sine of x (x is in radians)                      |
| sinh(x)      | Returns the hyperbolic sine of a double value                |
| tan(x)       | Returns the tangent of an angle                              |
| tanh(x)      | Returns the hyperbolic tangent of a double value             |



## Array

Declare an array (需声明空间大小)

```cpp
string cars[4];
string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
```



## Reference & Pointer

### reference

A reference variable is a "reference" to an existing variable, and it is created with the `&` operator:

```cpp
int main()
{
  string food = "pizza";
  string &meal = food;

  cout << food << "\n";  // pizza
  cout << meal << "\n";  // pizza
  cout << &food << "\n"; // 0x7ffee08708f0
  cout << &meal << "\n"; // 0x7ffee08708f0
  return 0;
}
```



### pointer

A **pointer** is a variable that **stores the memory address as its value**.

```cpp
string food = "Pizza";  // A food variable of type string
string* ptr = &food;    // A pointer variable, with the name ptr, that stores the address of food

// Output the value of food (Pizza)
cout << food << "\n";

// Output the memory address of food (0x6dfed4)
cout << &food << "\n";

// Output the memory address of food with the pointer (0x6dfed4)
cout << ptr << "\n";
```



## Function

```cpp
// Create a function
void myFunction() {
  cout << "I just got executed!";
}

int main() {
  myFunction(); // call the function
  return 0;
}

// Outputs "I just got executed!"
```

default param

```cpp
void myFunction(string country = "Norway") {
  cout << country << "\n";
}
```



## Class

```cpp
class MyClass {        // The class
  public:              // Access specifier
    void myMethod() {  // Method/function defined inside the class
      cout << "Hello World!";
    }
};

int main() {
  MyClass myObj;     // Create an object of MyClass
  myObj.myMethod();  // Call the method
  return 0;
}
```



define methods outside class def: `void MyClass::myMethod() `

```cpp
class MyClass {        // The class
  public:              // Access specifier
    void myMethod();   // Method/function declaration
};

// Method/function definition outside the class
void MyClass::myMethod() {
  cout << "Hello World!";
}

int main() {
  MyClass myObj;     // Create an object of MyClass
  myObj.myMethod();  // Call the method
  return 0;
}
```

### constructor

To create a constructor, use the same name as the class, followed by parentheses `()`:

```cpp
class Car {        // The class
  public:          // Access specifier
    string brand;  // Attribute
    string model;  // Attribute
    int year;      // Attribute
    Car(string x, string y, int z) { // Constructor with parameters
      brand = x;
      model = y;
      year = z;
    }
};

int main() {
  // Create Car objects and call the constructor with different values
  Car carObj1("BMW", "X5", 1999);
  Car carObj2("Ford", "Mustang", 1969);

  // Print values
  cout << carObj1.brand << " " << carObj1.model << " " << carObj1.year << "\n";
  cout << carObj2.brand << " " << carObj2.model << " " << carObj2.year << "\n";
  return 0;
}
```

### access specifier: `public`, `private`, `protected`

- `public` - members are accessible from outside the class
- `private` - members cannot be accessed (or viewed) from outside the class
- `protected` - members cannot be accessed from outside the class, however, they can be accessed in inherited classes. 

**Note:** By default, all members of a class are `private` if you don't specify an access specifier:

```cpp
class MyClass {
  int x;   // Private attribute
  int y;   // Private attribute
};
```



### Inheritance

```cpp
// Base class
class Vehicle {
  public:
    string brand = "Ford";
    void honk() {
      cout << "Tuut, tuut! \n" ;
    }
};

// Derived class
class Car: public Vehicle {
  public:
    string model = "Mustang";
};
```

Inherit multiple classes: `class MyChildClass: public MyClass, public MyOtherClass`

```cpp
// Base class
class MyClass {
  public:
    void myFunction() {
      cout << "Some content in parent class." ;
    }
};

// Another base class
class MyOtherClass {
  public:
    void myOtherFunction() {
      cout << "Some content in another class." ;
    }
};

// Derived class
class MyChildClass: public MyClass, public MyOtherClass {
};

int main() {
  MyChildClass myObj;
  myObj.myFunction();
  myObj.myOtherFunction();
  return 0;
}
```

#### `protected`

`protected`, is similar to `private`, but it can also be accessed in the **inherited** class:



### Polymorphism

perform a single action in different ways.

For example, think of a base class called `Animal` that has a method called `animalSound()`. Derived classes of Animals could be Pigs, Cats, Dogs, Birds - And they also have their own implementation of an animal sound (the pig oinks, and the cat meows, etc.):

```cpp
// Base class
class Animal {
  public:
    void animalSound() {
    cout << "The animal makes a sound \n" ;
  }
};

// Derived class
class Pig : public Animal {
  public:
    void animalSound() {
    cout << "The pig says: wee wee \n" ;
  }
};

// Derived class
class Dog : public Animal {
  public:
    void animalSound() {
    cout << "The dog says: bow wow \n" ;
  }
};
```

