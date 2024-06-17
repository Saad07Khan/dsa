#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

void encrypt(char *inputString, int encryptionKey)
{
    for (int i = 0; i < strlen(inputString); i++)
    {
        if (isalpha(inputString[i]))
        {
            char base = isupper(inputString[i]) ? 'A' : 'a';
            int shiftedChar = (inputString[i] - base + encryptionKey) % 26;
            inputString[i] = (shiftedChar + 26) % 26 + base;
        }
    }
}

void decrypt(char *inputString, int decryptionKey)
{
    encrypt(inputString, -decryptionKey);
}

int main()
{
    char inputString[100];
    int encryptionKey;

    cout << "Enter the message: ";
    cin.getline(inputString, sizeof(inputString));

    cout << "Enter the key: ";
    cin >> encryptionKey;

    encrypt(inputString, encryptionKey);
    cout << "Encrypted message: " << inputString << endl;

    decrypt(inputString, encryptionKey);
    cout << "Decrypted message: " << inputString << endl;

    return 0;
}
