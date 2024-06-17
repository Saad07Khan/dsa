class Solution {
public:
    string reverseWords(string s) {
        int n = s.size(); // Get the length of the input string.
        int i = 0; // Initialize a variable 'i' to 0 to track the current character position.
        string ans = ""; // Initialize an empty string 'ans' to store the reversed string.

        while (i < n) { // Start a loop that iterates through the characters of the input string.
            string temp = ""; // Initialize an empty string 'temp' to store a word.

            while (s[i] == ' ' && i < n) {
                i++; // Skip spaces by advancing 'i' while the current character is a space and 'i' is within the string's bounds.
            }

            while (s[i] != ' ' && i < n) {
                temp += s[i]; // Append characters to 'temp' to form a word until a space or the end of the string is encountered.
                i++; // Move to the next character.
            }

            if (temp.size() > 0) { // Check if 'temp' contains a non-empty word.
                if (ans.size() == 0) {
                    ans += temp; // If 'ans' is empty, directly append 'temp' to it.
                } else {
                    ans = temp + " " + ans; // If 'ans' is not empty, prepend 'temp' followed by a space to 'ans'.
                }
            }
        }
        return ans; // Return
