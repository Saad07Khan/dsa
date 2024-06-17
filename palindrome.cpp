#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

bool palindrome(char arr[], int n) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        // Convert characters to lowercase before comparing
        if (tolower(arr[low]) != tolower(arr[high])) {
            return false;
        } else {
            low++;
            high--;
        }
    }
    return true;
}

int main() {
    char arr[] = {'m', 'a', 'l', 'a', 'y', 'a', 'l', 'a', 'm'};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the actual length of the array

    if (palindrome(arr, n)) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not palindrome" << endl;
    }

    return 0;
}
