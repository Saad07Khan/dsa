#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int i, j, k, n;
    cout << "Enter the message: " << endl;
    string input, original;
    getline(cin, original);
    cout << "Enter the key: " << endl;
    string key;
    cin >> key;

    for (i = 0; i < original.size(); i++) {
        if (original[i] != ' ')
            input += original[i];
    }

    vector<vector<char>> grid(5, vector<char>(5, ' '));
    n = 5;
    map<char, int> charCount;
    k = 0;
    int pi, pj;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            while (charCount[key[k]] > 0 && k < key.size()) {
                k++;
            }
            if (k < key.size()) {
                grid[i][j] = key[k];
                charCount[key[k]]++;
                pi = i;
                pj = j;
            }
            if (k == key.size())
                break;
        }
        if (k == key.size())
            break;
    }

    k = 0;
    for (; i < n; i++) {
        for (; j < n; j++) {
            while (charCount[char(k + 'a')] > 0 && k < 26) {
                k++;
            }
            if (char(k + 'a') == 'j') {
                j--;
                k++;
                continue;
            }
            if (k < 26) {
                grid[i][j] = char(k + 'a');
                charCount[char(k + 'a')]++;
            }
        }
        j = 0;
    }

    string encrypted;
    if (input.size() % 2 == 1)
        input += 'x';

    for (i = 0; i < input.size() - 1; i++) {
        if (input[i] == input[i + 1])
            input[i + 1] = 'x';
    }

    map<char, pair<int, int>> charPosition;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            charPosition[grid[i][j]] = make_pair(i, j);
        }
    }

    for (i = 0; i < input.size() - 1; i += 2) {
        int y1 = charPosition[input[i]].first;
        int x1 = charPosition[input[i]].second;
        int y2 = charPosition[input[i + 1]].first;
        int x2 = charPosition[input[i + 1]].second;
        
        if (y1 == y2) {
            encrypted += grid[y1][(x1 + 1) % 5];
            encrypted += grid[y1][(x2 + 1) % 5];
        } else if (x1 == x2) {
            encrypted += grid[(y1 + 1) % 5][x1];
            encrypted += grid[(y2 + 1) % 5][x2];
        } else {
            encrypted += grid[y1][x2];
            encrypted += grid[y2][x1];
        }
    }

    cout << "Encrypted Text: " << encrypted << '\n';

    return 0;
}
