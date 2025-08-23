/*
 * ITESM-CQ
 * Objective : Understand the concept of pointers
 * Author    : Edward Alan Gomez (original), revised by Neo
 * Date      : March 14, 2018 (revised 2025)
 *
 * Program: Dynamically allocates an integer array, captures values using
 *          pointer arithmetic, and displays them (iteratively and recursively).
 */

#include <stdio.h>
#include <stdlib.h>

static void capture_ints(int* p, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        if (scanf("%d", p++) != 1) {
            // Basic fallback: stop on invalid input
            break;
        }
    }
}

static void display_iter(const int* p, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        printf("[%zu] = %d\n", i, *p++);
    }
}

static void display_rec(const int* p, size_t n) {
    if (n == 0) return;
    printf("%d\n", *p);
    display_rec(p + 1, n - 1);
}

int main(void) {
    int* data = NULL;
    size_t count = 0;

    printf("Enter the number of elements to capture -> ");
    if (scanf("%zu", &count) != 1 || count == 0) {
        fprintf(stderr, "Invalid size.\n");
        return 1;
    }

    data = malloc(sizeof *data * count);
    if (!data) {
        fprintf(stderr, "Out of memory.\n");
        return 1;
    }

    printf("Enter %zu integers separated by spaces/newlines:\n", count);
    capture_ints(data, count);

    printf("\nIterative display:\n");
    display_iter(data, count);

    printf("\nRecursive display:\n");
    display_rec(data, count);

    free(data);
    return 0;
}
