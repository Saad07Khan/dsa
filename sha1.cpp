#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate GCD (Euclidean algorithm)
int gcd(int a, int b) {
    if(b==0)
    {
        return a;
    }
    return gcd(b,a%b);
}

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

// Function to generate RSA keys
void generateRSAKeys(int p, int q, long long &n, long long e, long long &d) {
    n = p * q;
    long long phi = (p - 1) * (q - 1);

    // Compute 'd', the modular multiplicative inverse of 'e' modulo phi
    for (d = 2; d < phi; d++) {
        if ((d * e) % phi == 1) {
            break;
        }
    }
}

// RSA encryption function
long long rsaEncrypt(long long message, long long e, long long n) {
    return power(message, e, n);
}

// RSA decryption function
long long rsaDecrypt(long long cipher, long long d, long long n) {
    return power(cipher, d, n);
}

int main() {
    // Get prime numbers for RSA key generation
    int p, q;
    cout << "Enter two prime numbers (p and q): ";
    cin >> p >> q;

    long long n, e, d;
    long long phi = (p - 1) * (q - 1);

    // Get public key exponent 'e' from user
    cout << "Enter a value for 'e' (greater than 1, smaller than phi, and co-prime with phi): ";
    cin >> e;

    // Ensure 'e' meets the RSA constraints
    if (e < 2 || e >= phi || gcd(e, phi) != 1) {
        cout << "Invalid 'e'. Ensure it's co-prime with phi and smaller than phi." << endl;
        return 1; // Exit if 'e' is invalid
    }

    // Generate RSA keys
    generateRSAKeys(p, q, n, e, d);

    cout << "Public Key (n, e): (" << n << ", " << e << ")" << endl;
    cout << "Private Key (n, d): (" << n << ", " << d << ")" << endl;

    // Get the message to be encrypted
    long long message;
    cout << "Enter the message to be encrypted: ";
    cin >> message;

    // Encrypt the message
    long long encryptedMessage = rsaEncrypt(message, e, n);
    cout << "Encrypted Message: " << encryptedMessage << endl;

    // Decrypt the message
    long long decryptedMessage = rsaDecrypt(encryptedMessage, d, n);
    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}
