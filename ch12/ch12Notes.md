# Chapter 12: Member Functions

## General

- Member functions are functions defined inside of structs.
- They can be invoked to act on an instance of a struct.
- They can be declared inside a struct in a header file before being implemented in a seperate .cpp file.
- They can either be modifiers or pure functions.

## Definitions

1. **Invoke:** To call a function on an object or to pass the object as an implicit parameter of the function.
2. **Interface:** A description of how a function is used, including the number and types of parameters passed into the function. **Example:** `myFunction(int x, string y, double z)`
3. **Function Declaration:** A statement that declares the interface to a function by defining the parameters and the name of the function **without the function body**. Member functions can be declared in a struct, then implemented outside the struct. Example:

```C++
struct Rectangle {
    double length, width;

    void print();
    double area();
    double diagonalLength();
}

```

4. **Function implementation:** The body of a function which provides the details as to how it works.
5. **Constructor:** A special function that creates a new object by assigning values to its instance variables.
