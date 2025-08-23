# Pointer Squaring Demo

This program demonstrates:
- Declaring a pointer to an integer (`int* ptr`)
- Taking the address of a variable (`&value`)
- Printing memory addresses using `%p` and `(void*)`
- Dereferencing a pointer (`*ptr`) to read and modify a value

The program initializes an integer with the value `20`, prints its value and address, then squares the integer using the pointer (`*ptr *= *ptr`). Finally, it prints the updated values.

## Build & Run
```bash
gcc pointer_to_variable.c -o pointer_to_variable
./pointer_to_variable

Example:

Program that illustrates the use of pointers
The value of the variable is -> 20
The memory address of the variable is -> 0000009f4f3ffb34
The value through the pointer is -> 400
The value of the variable is -> 400
