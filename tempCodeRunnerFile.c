#include <stdio.h>

long long int power(long long int base, long long int exponent, long long int modulus) {
    long long int result = 1;
    base = base % modulus;

    while (exponent > 0) {
        if (exponent & 1)
            result = (result * base) % modulus;

        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }

    return result;
}

int main() {
    long long int P, G, a, b;

    printf("Enter the prime modulus (P): ");
    scanf("%lld", &P);
    printf("Enter the base (G): ");
    scanf("%lld", &G);

    printf("Enter Alice's private key (a): ");
    scanf("%lld", &a);

    printf("Enter Bob's private key (b): ");
    scanf("%lld", &b);

    long long int x = power(G, a, P);
    long long int y = power(G, b, P);

    long long int ka = power(y, a, P);
    long long int kb = power(x, b, P);

    printf("Secret key for Alice: %lld\n", ka);
    printf("Secret key for Bob: %lld\n", kb);

    return 0;
}
