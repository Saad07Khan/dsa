#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate GCD (Euclidean algorithm)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate modular exponentiation using built-in functions with double
double modularExponentiation(double base, double exponent, double modulus) {
    double powerResult = std::pow(base, exponent);
    double modResult = std::fmod(powerResult, modulus);
    return modResult;
}

// Generate RSA keys with a given public key exponent 'e'
void generateRSAKeys(int p, int q, double &n, double e, double &d) {
    n = static_cast<double>(p * q);
    double phi = static_cast<double>((p - 1) * (q - 1));

    // Validate 'e'
    if (e < 2 || e >= phi || gcd(static_cast<int>(e), static_cast<int>(phi)) != 1) {
        cout << "Invalid 'e'. Ensure it's co-prime with phi and smaller than phi." << endl;
        d = 0;  // Indicate failure if 'e' is invalid
        return;
    }

    // Compute 'd' such that (d * e) % phi == 1
    for (d = 2; d < phi; d++) {
        if (std::fmod(d * e, phi) == 1) {
            break;
        }
    }
}

// RSA encryption using double
double rsaEncrypt(double message, double e, double n) {
    return modularExponentiation(message, e, n);
}

// RSA decryption using double
double rsaDecrypt(double cipher, double d, double n) {
    return modularExponentiation(cipher, d, n);
}

int main() {
    // Get prime numbers for RSA key generation
    int p, q;
    cout << "Enter two prime numbers (p and q): ";
    cin >> p >> q;

    double n, e, d;
    cout << "Enter a value for 'e' (greater than 1, smaller than phi, and co-prime with phi): ";
    cin >> e;

    generateRSAKeys(p, q, n, e, d);

    if (d == 0) {
        cout << "Failed to generate valid RSA keys." << endl;
        return 1;  // Exit if key generation fails
    }

    cout << "Public Key (n, e): (" << n << ", " << e << ")" << endl;
    cout << "Private Key (n, d): (" << n << ", " << d << ")" << endl;

    // Get the message to be encrypted
    double message;
    cout << "Enter the message to be encrypted: ";
    cin >> message;

    // Encrypt the message
    double encryptedMessage = rsaEncrypt(message, e, n);

    cout << "Encrypted Message: " << encryptedMessage << endl;

    // Decrypt the message
    double decryptedMessage = rsaDecrypt(encryptedMessage, d, n);

    cout << "Decrypted Message: " << decryptedMessage << endl;

    return 0;
}
