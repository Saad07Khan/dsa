// main.cpp - Your main C++ file

#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <climits>

using namespace std;

int findMinimumSubstringLength(string str) {
    unordered_set<char> st;
    int n = str.length();
    int ans = INT_MAX;
    unordered_map<char, int> mp;

    for (int i = 0; i < n; i++) {
        st.insert(str[i]);
    }

    int i = 0;
    int j = 0;

    while (i < n) {
        mp[str[i]]++;

        if (mp.size() == st.size()) {
            while (mp[str[j]] > 1) {
                mp[str[j]]--;
                j++;
            }

            ans = min(ans, i - j + 1); // Calculate the length of the substring and update ans.
        }

        i++;
    }

    return ans;
}

int main() {
    string input_string = "YourInputStringHere"; // Replace with your input string
    int result = findMinimumSubstringLength(input_string);
    cout << "Minimum substring length: " << result << endl;
    return 0;
}
