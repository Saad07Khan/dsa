#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

#define MATRIX_SIZE 5

void prepareKey(char userKey[], char keyMatrix[MATRIX_SIZE][MATRIX_SIZE])
{
    char uniqueChars[26] = {0};
    char alphabet[] = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
    int keyLen = strlen(userKey);
    int i, j, k = 0;

    for (i = 0; i < keyLen; i++)
    {
        if (userKey[i] == 'J')
        {
            userKey[i] = 'I';
        }
        userKey[i] = toupper(userKey[i]);
    }

    for (i = 0; i < keyLen; i++)
    {
        if (uniqueChars[userKey[i] - 'A'] == 0)
        {
            uniqueChars[userKey[i] - 'A'] = 1;
            keyMatrix[k / MATRIX_SIZE][k % MATRIX_SIZE] = userKey[i];
            k++;
        }
    }

    for (i = 0; i < 26; i++)
    {
        if (uniqueChars[alphabet[i] - 'A'] == 0)
        {
            keyMatrix[k / MATRIX_SIZE][k % MATRIX_SIZE] = alphabet[i];
            k++;
        }
    }
}

void findPosition(char keyMatrix[MATRIX_SIZE][MATRIX_SIZE], char ch, int *row, int *col)
{
    if (ch == 'J')
    {
        ch = 'I';
    }

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            if (keyMatrix[i][j] == ch)
            {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encrypt(char keyMatrix[MATRIX_SIZE][MATRIX_SIZE], char plaintext[])
{
    int len = strlen(plaintext);
    char ciphertext[len * 2];
    int index = 0;

    for (int i = 0; i < len; i += 2)
    {
        char a = plaintext[i];
        char b = (i + 1 < len) ? plaintext[i + 1] : 'X';
        int rowA, colA, rowB, colB;
        findPosition(keyMatrix, a, &rowA, &colA);
        findPosition(keyMatrix, b, &rowB, &colB);

        if (rowA == rowB)
        {
            ciphertext[index++] = keyMatrix[rowA][(colA + 1) % MATRIX_SIZE];
            ciphertext[index++] = keyMatrix[rowB][(colB + 1) % MATRIX_SIZE];
        }
        else if (colA == colB)
        {
            ciphertext[index++] = keyMatrix[(rowA + 1) % MATRIX_SIZE][colA];
            ciphertext[index++] = keyMatrix[(rowB + 1) % MATRIX_SIZE][colB];
        }
        else
        {
            ciphertext[index++] = keyMatrix[rowA][colB];
            ciphertext[index++] = keyMatrix[rowB][colA];
        }
    }

    ciphertext[index] = '\0';
    cout << "Encrypted Text: " << ciphertext << endl;
}

void decrypt(char keyMatrix[MATRIX_SIZE][MATRIX_SIZE], char ciphertext[])
{
    int len = strlen(ciphertext);
    char decrypted[len * 2];
    int index = 0;

    for (int i = 0; i < len; i += 2)
    {
        char a = ciphertext[i];
        char b = ciphertext[i + 1];
        int rowA, colA, rowB, colB;
        findPosition(keyMatrix, a, &rowA, &colA);
        findPosition(keyMatrix, b, &rowB, &colB);

        if (rowA == rowB)
        {
            decrypted[index++] = keyMatrix[rowA][(colA - 1 + MATRIX_SIZE) % MATRIX_SIZE];
            decrypted[index++] = keyMatrix[rowB][(colB - 1 + MATRIX_SIZE) % MATRIX_SIZE];
        }
        else if (colA == colB)
        {
            decrypted[index++] = keyMatrix[(rowA - 1 + MATRIX_SIZE) % MATRIX_SIZE][colA];
            decrypted[index++] = keyMatrix[(rowB - 1 + MATRIX_SIZE) % MATRIX_SIZE][colB];
        }
        else
        {
            decrypted[index++] = keyMatrix[rowA][colB];
            decrypted[index++] = keyMatrix[rowB][colA];
        }
    }

    decrypted[index] = '\0';
    cout << "Decrypted Text: " << decrypted << endl;
}

int main()
{
    char userKey[MATRIX_SIZE * MATRIX_SIZE];
    char keyMatrix[MATRIX_SIZE][MATRIX_SIZE];
    char plaintext[100];

    cout << "Enter the key: ";
    cin.getline(userKey, sizeof(userKey));
    userKey[strcspn(userKey, "\n")] = '\0';

    prepareKey(userKey, keyMatrix);

    cout << "Enter the plaintext: ";
    cin.getline(plaintext, sizeof(plaintext));
    plaintext[strcspn(plaintext, "\n")] = '\0';

    cout << "\nKey Table:\n";
    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        for (int j = 0; j < MATRIX_SIZE; j++)
        {
            cout << keyMatrix[i][j] << "\t";
        }
        cout << endl;
    }

    encrypt(keyMatrix, plaintext);
    decrypt(keyMatrix, plaintext);

    return 0;
}
