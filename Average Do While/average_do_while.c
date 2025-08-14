/*
 * ITESM-CQ
 * Objective : Understand the use of the do-while loop
 * Authors   : Oscar Hernandez (original) and Edward Gomez (revised)
 * Date      : March 14, 2018 (revised 2025)
 *
 * Program: Calculates the average of a list of integers entered by the user.
 *          Enter 0 to end input.
 */

#include <stdio.h>

#define MSG_INIT  "\nProgram that calculates the average of a list of numbers\nEnter 0 to finish"
#define MSG_INPUT "\nEnter an integer -> "
#define MSG_END   "\nThe average of the %d %s is %.2f\n"

int main(void) {
    int   num, count = 0;
    float avg = 0.0f, sum = 0.0f;

    printf(MSG_INIT);

    do {
        printf(MSG_INPUT);
        if (scanf("%d", &num) != 1) {
            fprintf(stderr, "Invalid input. Exiting.\n");
            return 1;
        }
        if (num != 0) {  // only count non-zero entries
            sum += num;
            count++;
        }
    } while (num != 0);

    if (count > 0) {
        avg = sum / count;
        printf(MSG_END, count, (count == 1 ? "number" : "numbers"), avg);
    } else {
        printf("\nNo numbers entered. Average is undefined.\n");
    }

    return 0;
}
