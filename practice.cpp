#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

// Permutation Choice 2 table
const int PC2[48] = { 14, 17, 11, 24, 1, 5,
 3, 28, 15, 6, 21, 10,
 23, 19, 12, 4, 26, 8,
 16, 7, 27, 20, 13, 2,
 41, 52, 31, 37, 47, 55,
 30, 40, 51, 45, 33, 48,
 44, 49, 39, 56, 34, 53,
 46, 42, 50, 36, 29, 32 };

// Circular left shift function
bitset<28> leftShift(bitset<28> bits, int shift) {
    return (bits << shift) | (bits >> (28 - shift));
}

// Apply PC2 table to generate K1
bitset<48> applyPC2(bitset<56> key) {
    bitset<48> K1;
    for (int i = 0; i < 48; ++i) {
        K1[i] = key[PC2[i] - 1];
    }
    return K1;
}

int main() {
    // Input the 56-bit permutation key
    string key_input;
    cout << "Enter the 56-bit permutation key (C1D1): ";
    cin >> key_input;

    // Convert input key to bitset
    bitset<56> key(key_input);

    // Input the number of left shifts
    int num_shifts;
    cout << "Enter the number of left shifts: ";
    cin >> num_shifts;

    // Perform circular left shifts
    key = (key << num_shifts) | (key >> (56 - num_shifts));

    // Separate C and D parts of the key
    bitset<28> C = bitset<28>(key.to_string().substr(0, 28));
    bitset<28> D = bitset<28>(key.to_string().substr(28, 28));

    // Generate K1 by applying PC2 table
    bitset<48> K1 = applyPC2(key);

    // Output K1
    cout << "Key K1 after applying PC2 table: " << K1 << endl;

    return 0;
}