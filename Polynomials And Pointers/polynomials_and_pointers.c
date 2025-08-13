/*
 * ITESM-CQ
 * Objective : Practice dynamic memory and pointer-based lists (polynomials)
 * Author    : Original by Oscar Hernandez; revised by Edward (2025)
 *
 * Features:
 *  - Singly linked list representing a polynomial: Σ (coef * x^exp)
 *  - Append-at-end insertion
 *  - Pretty printing (no trailing '+', handles x, x^n, constants)
 *  - Derivative and integral (in-place)
 *  - Safe I/O; coef 0 ends input
 *
 * Notes:
 *  - Uses double for coefficients to avoid truncation during integration.
 *  - Iterative implementations avoid recursion depth limits.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    double         coef;  // coefficient
    int            exp;   // exponent (>= 0)
    struct Node*   next;
} Node;

/* Allocate and initialize a new node */
static Node* new_node(double coef, int exp) {
    Node* n = (Node*)malloc(sizeof *n);
    if (!n) return NULL;
    n->coef = coef;
    n->exp  = exp;
    n->next = NULL;
    return n;
}

/* Append at the end; returns false on OOM */
static bool insert_back(Node** head, double coef, int exp) {
    if (!head) return false;
    Node* n = new_node(coef, exp);
    if (!n) return false;

    if (*head == NULL) {
        *head = n;
        return true;
    }
    Node* cur = *head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    return true;
}

/* Pretty-print one term into stdout */
static void print_term(double coef, int exp, bool first) {
    // Handle sign and absolute value printing
    if (first) {
        // Leading sign: print '-' if negative, nothing if positive
        if (coef < 0) { printf("-"); coef = -coef; }
    } else {
        printf(coef < 0 ? " - " : " + ");
        if (coef < 0) coef = -coef;
    }

    // Decide how to render coefficient/exponent
    if (exp == 0) {
        // Constant term
        printf("%.2f", coef);
    } else if (exp == 1) {
        // x to the first
        if (coef == 1.0)        printf("x");
        else                    printf("%.2fx", coef);
    } else {
        if (coef == 1.0)        printf("x^%d", exp);
        else                    printf("%.2fx^%d", coef, exp);
    }
}

/* Display the polynomial: e.g., -3.00x^2 + 2.00x - 5.00 */
static void display_poly(const Node* head) {
    if (!head) { printf("(empty)\n"); return; }

    const Node* cur = head;
    bool first = true;
    bool anything = false;

    while (cur) {
        if (cur->coef != 0.0) {
            print_term(cur->coef, cur->exp, first);
            first = false;
            anything = true;
        }
        cur = cur->next;
    }
    if (!anything) printf("0");
    printf("\n");
}

/* In-place derivative: d/dx (c*x^e) = (c*e)*x^(e-1); constant term vanishes */
static void derivative(Node* head) {
    for (Node* cur = head; cur; cur = cur->next) {
        if (cur->exp == 0) {
            cur->coef = 0.0; // derivative of constant is 0
        } else {
            cur->coef = cur->coef * cur->exp;
            cur->exp  = cur->exp - 1;
        }
    }
}

/* In-place integral (no constant of integration): ∫ c*x^e dx = c/(e+1) * x^(e+1) */
static void integral(Node* head) {
    for (Node* cur = head; cur; cur = cur->next) {
        cur->exp  = cur->exp + 1;
        cur->coef = cur->coef / cur->exp; // safe because exp>=0 originally
    }
}

/* Free list and null the head */
static void free_list(Node** head) {
    if (!head) return;
    Node* cur = *head;
    while (cur) {
        Node* nxt = cur->next;
        free(cur);
        cur = nxt;
    }
    *head = NULL;
}

/* Deep copy the list */
static Node* copy_list(const Node* head) {
    Node* copy = NULL;
    Node* tail = NULL;
    for (const Node* cur = head; cur; cur = cur->next) {
        Node* n = new_node(cur->coef, cur->exp);
        if (!n) { free_list(&copy); return NULL; }
        if (!copy) {
            copy = tail = n;
        } else {
            tail->next = n;
            tail = n;
        }
    }
    return copy;
}

int main(void) {
    Node* poly = NULL;

    printf("Enter pairs: <coefficient> <exponent>. Enter coef 0 to end.\n");
    printf("Example: 3 2   means 3*x^2\n\n");

    while (1) {
        double c; int e;
        printf("coef exp -> ");
        int rc = scanf("%lf %d", &c, &e);
        if (rc != 2) {
            fprintf(stderr, "Invalid input. Exiting.\n");
            free_list(&poly);
            return EXIT_FAILURE;
        }
        if (c == 0.0) break;              // coef 0 ends input
        if (e < 0) {
            fprintf(stderr, "Exponent must be >= 0. Try again.\n");
            continue;
        }
        if (!insert_back(&poly, c, e)) {
            fprintf(stderr, "Out of memory.\n");
            free_list(&poly);
            return EXIT_FAILURE;
        }
    }

    printf("\nPolynomial: ");
    display_poly(poly);

    Node* deriv = copy_list(poly);
    if (!deriv && poly) { 
        fprintf(stderr, "Out of memory.\n");
        free_list(&poly);
        return EXIT_FAILURE;
    }

    if (deriv) {
        derivative(deriv);
        printf("Derivative (of original): ");
        display_poly(deriv);
    } else {
        printf("Derivative (of original): (empty)\n");
    }

    printf("Integral (of original, no +C): ");
    integral(poly);
    display_poly(poly);

    free_list(&poly);
    free_list(&deriv);
    return EXIT_SUCCESS;
}
