#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

char *encrypt(const char *message, const char *key)
{
    int len = strlen(message);
    char *encrypted = new char[len + 1];

    for (int i = 0; i < len; i++)
    {
        if (isalpha(message[i]))
        {
            encrypted[i] = ((toupper(message[i]) - 'A') + (toupper(key[i]) - 'A')) % 26 + 'A';
        }
        else
        {
            encrypted[i] = message[i];
        }
    }

    encrypted[len] = '\0';
    return encrypted;
}

char *decrypt(const char *encrypted, const char *key)
{
    int len = strlen(encrypted);
    char *decrypted = new char[len + 1];

    for (int i = 0; i < len; i++)
    {
        if (isalpha(encrypted[i]))
        {
            decrypted[i] = ((toupper(encrypted[i]) - 'A') - (toupper(key[i]) - 'A') + 26) % 26 + 'A';
        }
        else
        {
            decrypted[i] = encrypted[i];
        }
    }

    decrypted[len] = '\0';
    return decrypted;
}

int main()
{
    char message[100], key[100];
    cout << "Enter the message: ";
    cin.getline(message, sizeof(message));
    cout << "Enter the key: ";
    cin.getline(key, sizeof(key));

    if (strlen(message) != strlen(key))
    {
        cout << "Error: Message and key must be of the same length." << endl;
        return 1;
    }

    char *encrypted = encrypt(message, key);
    cout << "Encrypted message: " << encrypted << endl;

    char *decrypted = decrypt(encrypted, key);
    cout << "Decrypted message: " << decrypted << endl;

    delete[] encrypted;
    delete[] decrypted;

    return 0;
}
