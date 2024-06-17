#include <iostream>
#include <cstring>

using namespace std;

char encrypt(char c, char key)
{
    if (c >= 'A' && c <= 'Z')
    {
        return ((c + key - 2 * 'A') % 26) + 'A';
    }
    else if (c >= 'a' && c <= 'z')
    {
        return ((c + key - 2 * 'a') % 26) + 'a';
    }
    else
    {
        return c;
    }
}

char decrypt(char c, char key)
{
    if (c >= 'A' && c <= 'Z')
    {
        return ((c - key + 26) % 26) + 'A';
    }
    else if (c >= 'a' && c <= 'z')
    {
        return ((c - key + 26) % 26) + 'a';
    }
    else
    {
        return c;
    }
}

void vigenereEncrypt(char *text, char *key, char *result)
{
    int len = strlen(text);
    int keyLen = strlen(key);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        result[i] = encrypt(text[i], key[j]);
        j = (j + 1) % keyLen;
    }
    result[len] = '\0';
}

void vigenereDecrypt(char *text, char *key, char *result)
{
    int len = strlen(text);
    int keyLen = strlen(key);
    int j = 0;
    for (int i = 0; i < len; i++)
    {
        result[i] = decrypt(text[i], key[j]);
        j = (j + 1) % keyLen;
    }
    result[len] = '\0';
}

int main()
{
    char cipherKey[100], plaintext[100], encryptedText[100], decryptedText[100];

    cout << "Enter the key: ";
    cin >> cipherKey;
    cout << "Enter the message for encryption: ";
    cin >> plaintext;

    vigenereEncrypt(plaintext, cipherKey, encryptedText);
    cout << "String: " << plaintext << endl;
    cout << "Encrypted message: Cipher Text = " << encryptedText << endl;

    vigenereDecrypt(encryptedText, cipherKey, decryptedText);
    cout << "Decrypted message: Plain Text = " << decryptedText << endl;

    return 0;
}
