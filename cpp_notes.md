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

