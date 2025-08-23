/*
 * ITESM-CQ
 * Objective : Illustrate basic pointer usage
 * Authors   : Oscar Hernandez (original), Edward Gomez (revised)
 * Date      : Sept 26, 1995 (revised 2025)
 *
 * Program: Demonstrates variable address, pointer dereferencing,
 *          and modifying a value through a pointer.
 */

#include <stdio.h>

#define INTRO "\nProgram that illustrates the use of pointers"

int main(void) {
    int  value = 20;     // initial value
    int* ptr   = &value; // pointer to 'value'

    printf(INTRO);

    // Print the variable's value and memory address
    printf("\nThe value of the variable is -> %d", value);
    printf("\nThe memory address of the variable is -> %p", (void*)&value);

    // Modify the variable via pointer dereference
    *ptr *= *ptr; // equivalent to: value = value * value;

    printf("\nThe value through the pointer is -> %d", *ptr);
    printf("\nThe value of the variable is -> %d\n", value);
    return 0;
}
