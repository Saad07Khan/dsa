#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <openssl/aes.h>

#define BLOCK_SIZE 8 // 64-bit block size
#define KEY_SIZE 32   // 256-bit key size

void aes_encrypt(const uint8_t *input, const uint8_t *key, uint8_t *output) {
    AES_KEY aes_key;
    AES_set_encrypt_key(key, KEY_SIZE * 8, &aes_key);
    AES_encrypt(input, output, &aes_key);
}

void aes_decrypt(const uint8_t *input, const uint8_t *key, uint8_t *output) {
    AES_KEY aes_key;
    AES_set_decrypt_key(key, KEY_SIZE * 8, &aes_key);
    AES_decrypt(input, output, &aes_key);
}

int main() {
    uint8_t key[KEY_SIZE];
    uint8_t input[BLOCK_SIZE];
    uint8_t encrypted[BLOCK_SIZE], decrypted[BLOCK_SIZE];

    printf("Enter 256-bit key (32 characters): ");
    if(scanf("%32s", key) != 1) {
        printf("Invalid key input.\n");
        return 1;
    }

    printf("Enter plaintext (up to 8 characters): ");
    if(scanf("%8s", input) != 1) {
        printf("Invalid plaintext input.\n");
        return 1;
    }

    // Encrypt
    aes_encrypt(input, key, encrypted);

    // Decrypt
    aes_decrypt(encrypted, key, decrypted);

    printf("Original: %s\n", input);
    printf("Encrypted: ");
    for (int i = 0; i < BLOCK_SIZE; ++i) {
        printf("%02x ", encrypted[i]);
    }
    printf("\n");

    printf("Decrypted: %s\n", decrypted);

    return 0;
}
