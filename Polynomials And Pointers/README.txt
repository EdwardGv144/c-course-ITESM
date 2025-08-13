# Polynomial with Linked List (Dynamic Memory)

This program practices **dynamic memory** and **pointer-based lists** by representing a polynomial
as a singly linked list of terms `(coef, exp)`:

c0x^e0 + c1x^e1 + ...

## Features
- Append terms at the end (input-driven)
- Pretty printer (no trailing `+`, handles `x`, `x^n`, and constants)
- In-place **derivative** and **integral** (no +C)
- Safe I/O; **enter coefficient 0 to end input**

## Input
Enter pairs:
<coefficient> <exponent>
- Example: `3 2` means `3*x^2`
- **Enter `0 <anything>` to end**, e.g. `0 0`

## Build & Run
```bash
gcc -Wall -Wextra -O2 -o poly main.c
./poly

## Example:
Enter pairs: <coefficient> <exponent>. Enter coef 0 to end.
Example: 3 2   means 3*x^2

coef exp -> 3
2
coef exp -> 2
1
coef exp -> 5
0
coef exp -> 0
0

Polynomial: 3.00x^2 + 2.00x + 5.00
Derivative (of original): 6.00x + 2.00
Integral (of original, no +C): x^3 + x^2 + 5.00x