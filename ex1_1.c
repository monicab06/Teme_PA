#include <stdio.h>

// fibbonacci recursiv
long long fibonacci_recursiv(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursiv(n - 1) + fibonacci_recursiv(n - 2);
}

int main() {
    int n = 10;
    printf("Termenul %d (recursiv): %lld\n", n, fibonacci_recursiv(n));
    return 0;
}
