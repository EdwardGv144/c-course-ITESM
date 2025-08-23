/*
 * ITESM-CQ
 * Objective : Practice pointers via a singly linked list
 * Author    : Edward Alan Gomez
 * Date      : March 14, 2018 (revised 2025)
 *
 * Features:
 *  - Append to end of list
 *  - Display list
 *  - Find element through value or pointer
 *  - Free all nodes
 *  - Prompts: enter integers; 0 ends input; then enter key to search
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int            value;
    struct Node*   next;
} Node;

/* Allocate and initialize a new node */
static Node* new_node(int value) {
    Node* n = (Node*)malloc(sizeof *n);
    if (!n) return NULL;
    n->value = value;
    n->next  = NULL;
    return n;
}

/* Append value at the end of the list. Returns false on OOM. */
static bool insert_back(Node** head, int value) {
    if (!head) return false;

    if (*head == NULL) {
        *head = new_node(value);
        return *head != NULL;
    }

    Node* cur = *head;
    while (cur->next) cur = cur->next;

    cur->next = new_node(value);
    return cur->next != NULL;
}

/* Print the list contents */
static void display(const Node* head) {
    const Node* cur = head;
    if (!head) {
        printf("(empty)\n");
        return;
    }
    const Node* cur = head;
    while (cur) {
        printf("%5d", cur->value);
        cur = cur->next;
    }
    printf("\n");
}

/* Return true if target exists in the list */
static bool find_bool(const Node* head, int target) {
    for (const Node* cur = head; cur; cur = cur->next) {
        if (cur->value == target) return true;
    }
    return false;
}

/* Return pointer to the node that holds target, or NULL if not found */
static Node* find_ptr(Node* head, int target) {
    for (Node* cur = head; cur; cur = cur->next) {
        if (cur->value == target) return cur;
    }
    return NULL;
}

/* Free all nodes and set *head = NULL */
static void free_list(Node** head) {
    if (!head) return;
    Node* cur = *head;
    while (cur) {
        Node* next = cur->next;
        free(cur);
        cur = next;
    }
    *head = NULL;
}

int main(void) {
    Node* head = NULL;

    printf("Enter integers to build the list (enter 0 to end): ");
    int num;
    while (scanf("%d", &num) == 1 && num != 0) {
        if (!insert_back(&head, num)) {
            fprintf(stderr, "\nError: out of memory.\n");
            free_list(&head);
            return EXIT_FAILURE;
        }
    }

    printf("List contents: ");
    display(head);

    printf("Enter key to search: ");
    int key;
    if (scanf("%d", &key) != 1) {
        fprintf(stderr, "Invalid input.\n");
        free_list(&head);
        return EXIT_FAILURE;
    }

    /* First: boolean search */
    if (find_bool(head, key)) {
        printf("Found element!\n");
        /* Second: pointer search (and print what we found) only if boolean search successful */
        Node* p = find_ptr(head, key);
        if (p) {
        printf("Pointer at %p with value %d\n", (void*)p, p->value);
        } else {
            printf("Element not found through pointer search");
        }
    } else {
        printf("Element not found");
    }

    free_list(&head);
    return EXIT_SUCCESS;
}
