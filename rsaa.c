#include <stdio.h>

long long gcdExtended(long long a, long long b, long long *x, long long *y) {
    // Base Case
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }

    long long x1, y1; // To store results of recursive call
    long long gcd = gcdExtended(b % a, a, &x1, &y1);

    // Update x and y using results of recursive
    // call
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

// Function to find modulo inverse of a
long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = gcdExtended(a, m, &x, &y);
    if (g != 1) {
        return -1; // Modular inverse doesn't exist
    } else {
        // m is added to handle negative x
        return (x % m + m) % m;
    }
}

int main() {
    // Initialize values
    long long p = 11612199208603481528191203480311138551131149330910969186013508178404897667309957981373053390778586834303644813108843225775203643345752164528840671055453193LL;
    long long q = 10073741008106865231276389795238965771248709323399675549509790429942012945286671740622989252694044360794601045743713058132608416216317245870942597743372319LL;
    long long e = 65537LL;

    // Calculate phi(n)
    long long phi_n = (p - 1) * (q - 1);

    // Calculate d (modular inverse of e)
    long long d = modInverse(e, phi_n);

    // Print d
    printf("d = %lld\n", d);

    return 0;
}
