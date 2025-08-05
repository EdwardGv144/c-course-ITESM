#include <stdio.h>

// Recursive function to calculate factorial of N
unsigned long int Fact(int N) {
    if (N > 0)
        return (unsigned long int)(N * Fact(N - 1));
    else
        return 1;
}

int main() {
    // Warning: 45! exceeds the range of long int
    printf("%llu\n", Fact(20));
    return 0;
}
