/*
 * ITESM-CQ
 * Objective : Understand pointers and pointer arithmetic
 * Authors   : Oscar Hernandez (original) and Edward Gomez (revised)
 * Date      : March 14, 2018 (revised 2025)
 *
 * Program: Demonstrates pointer arithmetic by printing memory addresses
 *          and the contents at those addresses.
 */

#include <stdio.h>

#define WINDOW_SIZE 20

int main(void) {
    int x = -1;                // starting value
    int* ptr = &x;             // pointer to x

    printf("\n   Address of counter variable x = %p\n", (void*)&x);

    printf("\n   Address         Content\n");
    for (int i = 0; i < WINDOW_SIZE; i++) {
        printf("   %p   [%7d]\n", (void*)ptr, *ptr);
        ptr++;  // advance pointer to next int
    }

    // Wait for user input before exiting (optional)
    printf("\nPress Enter to exit...");
    getchar();

    return 0;
}
