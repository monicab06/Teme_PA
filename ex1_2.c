#include <stdio.h>

// fibbonacci iterativ
long long fibonacci_iterativ(int n) {
    if (n <= 1)
        return n;
    
    long long prev2 = 0, prev1 = 1, current;
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", fibonacci_iterativ(n));
    return 0;
}
