#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate modular exponentiation
long long power(long long base, long long exponent, long long modulus) {
    long long result = 1;
    base = base % modulus;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % modulus;
        }
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

// Function to generate ElGamal keys
void generateElGamalKeys(int p, int g, int x, long long &y) {
    y = power(g, x, p); // Public key y = g^x mod p
}

// Function to perform ElGamal encryption
void elGamalEncrypt(int p, int g, int y, int k, int message, long long &c1, long long &c2) {
    c1 = power(g, k, p); // First part of the ciphertext
    long long temp = power(y, k, p); // Shared secret
    c2 = (message * temp) % p; // Second part of the ciphertext
}

// Function to perform ElGamal decryption
int elGamalDecrypt(int p, int x, long long c1, long long c2) {
    long long temp = power(c1, x, p); // Shared secret
    long long temp2 = (c2 * power(temp, p - 2, p)) % p; // Decrypted message
    return static_cast<int>(temp2); // Convert to int
}

int main() {
    int p, g, x, k, message;

    cout << "Enter a prime number (p): ";
    cin >> p;

    cout << "Enter a primitive root (g): ";
    cin >> g;

    cout << "Enter a private key (x): ";
    cin >> x;

    cout << "Enter a random number (k): ";
    cin >> k;

    cout << "Enter the message to be encrypted: ";
    cin >> message;

    long long y;
    generateElGamalKeys(p, g, x, y);

    cout << "Public Key (p, g, y): (" << p << ", " << g << ", " << y << ")" << endl;

    long long c1, c2;
    elGamalEncrypt(p, g, y, k, message, c1, c2);

    cout << "Encrypted Message: (" << c1 << ", " << c2 << ")" << endl;

    int decryptedMessage = elGamalDecrypt(p, x, c1, c2);

    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}
