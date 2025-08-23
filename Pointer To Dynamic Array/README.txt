# Pointer-Based Array Capture and Display

This program demonstrates basic pointer arithmetic in C:

- Dynamically allocates an integer array (`malloc`)
- Captures values using a pointer that advances (`p++`)
- Displays values both **iteratively** and **recursively**

## Build & Run
```bash
gcc pointer_to_dynamic_array.c -o ptr_dyn_arr
./ptr_dyn_arr

Example:
Enter the number of elements to capture -> 5
Enter 5 integers separated by spaces/newlines:
3
5
6
1
7

Iterative display:
[0] = 3
[1] = 5
[2] = 6
[3] = 1
[4] = 7

Recursive display:
3
5
6
1
7
