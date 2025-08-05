# Recursive Factorial

This program demonstrates the use of recursion to compute the factorial of a number.

## Summary

- Uses a recursive function `Fact(N)` to compute `N!`
- The return type is `unsigned long int`, which allows handling larger values than `int`
- Calculates and prints `20!`, the largest factorial that fits safely within an `unsigned long int`

## Example Output

2192834560

## Overflow Consideration

Although this program allows computing factorials of numbers larger than 12 or 13 (which would overflow a regular `int`), it still has a limit:

- `20!` fits safely into a 64-bit `unsigned long int`
- `21!` and above will **overflow**, producing incorrect (often negative or wrapped) results

For calculations beyond `20!`, a big number library such as GMP or manual array-based multiplication is required.

## How to Compile

```bash
gcc factorial.c -o factorial
./factorial
