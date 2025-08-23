# Singly Linked List (Pointers Practice)

This program demonstrates pointer usage by implementing a basic singly linked list with:
- Append (insert at end)
- Display
- Search by value (boolean)
- Search returning a node pointer
- Free the entire list

## How it works
1. You enter integers to build the list. **Enter `0` to end input**.
2. The program prints the list.
3. You enter a **key** to search.
4. It searches twice:
   - Using a boolean check — prints “Found element through value …”
   - Using a pointer-returning search — prints “Found element through pointer …” and shows the node address.

## Build & Run
```bash
gcc pointers_single_linkedlist.c -o list
./list

Example at Terminal:
Enter integers to build the list (enter 0 to end): 3
7
9
4
0
List contents:     3    7    9    4
Enter key to search: 9
Found element through value: 9
Found element through pointer at 0x... with value 9

Note: Addresses vary per run.

