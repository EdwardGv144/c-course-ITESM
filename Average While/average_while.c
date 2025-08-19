/*
 * ITESM-CQ
 * Objective : Understand the use of the iterative WHILE loop
 * Authors   : Oscar Hernandez (original) and Edward Gomez (revised)
 * Date      : March 14, 2018 (revised 2025)
 *
 * Program: Calculates the average of N numbers using a counter-controlled while loop.
 */

#include <stdio.h>

#define MSG_TITLE   "\nProgram to calculate the average of N numbers"
#define MSG_PROMPTN "\nEnter the number of elements to capture -> "
#define MSG_ELEM    "Enter element [%d] -> "
#define MSG_RESULT  "\nThe average is %.5f\n"

int main(void) {
    int    N, count = 0;
    double sum = 0.0, avg = 0.0, x = 0.0;

    printf(MSG_TITLE);
    printf(MSG_PROMPTN);

    if (scanf("%d", &N) != 1) {
        fprintf(stderr, "Invalid input for N. Exiting.\n");
        return 1;
    }
    if (N <= 0) {
        printf("\nN must be a positive integer. Nothing to do.\n");
        return 0;
    }

    while (count < N) {
        printf(MSG_ELEM, count + 1);
        if (scanf("%lf", &x) != 1) {
            fprintf(stderr, "Invalid number. Exiting.\n");
            return 1;
        }
        sum += x;
        count++;
    }

    avg = sum / N;
    printf(MSG_RESULT, avg);
    return 0;
}
