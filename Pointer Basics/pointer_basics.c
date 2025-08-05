/*
 * ITESM Campus Querétaro
 * Objective : Understand the concept of pointers in C
 * Author    : Edward Alan Gomez
 * Date      : March 14, 2018
 */

#include <stdio.h>

int main(void) {
    int x = 1024;
    int* p = &x;  // Pointer to variable x

    // Print the address and value of x directly
    printf("[%p] = %d\n", (void*)&x, x);

    // Print the address stored in p and the value pointed to
    printf("[%p] = %d\n", (void*)p, *p);

    return 0;
}
