/*
 * ITESM-CQ
 * Objective : Understand pointer usage with character arrays
 * Authors   : Oscar Hernandez (original), Edward Gomez (revised)
 * Date      : March 14, 2018 (revised 2025)
 *
 * Program: Demonstrates iterating over a string with a pointer,
 *          advancing with the increment (++) operator.
 */

#include <stdio.h>

#define INTRO  "\nProgram that illustrates the use of pointers with strings"
#define OUTPUT "\nThe contents of the array are:\n"

int main(void) {
    // Declare and initialize a character array (string)
    char message[50] = "TECNOLOGICO DE MONTERREY";

    // Pointer to a character
    char* ptr;

    printf(INTRO);
    printf(OUTPUT);

    // Make pointer point to the first character of the array
    ptr = &message[0];

    // Loop through the array using the pointer until null terminator is reached
    while (*ptr != '\0') {
        printf("%c", *ptr);  // Print the character being pointed to
        ptr++;               // Advance the pointer to the next character
    }

    printf("\n");
    return 0;
}
