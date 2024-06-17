class Solution {
public:
string removeOuterParentheses(string s) {
    string ans = ""; // Initialize an empty string to store the result.
    int count = 0;   // Initialize a counter to keep track of the balance of parentheses.

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') { // If an opening parenthesis is encountered:
            if (count > 0) {
                ans += s[i]; // If the count is greater than 0 (not the outermost opening parenthesis), add it to the result.
            }
            count++; // Increment the count to maintain the balance.
        } else if (s[i] == ')') { // If a closing parenthesis is encountered:
            count--; // Decrement the count to maintain the balance.
            if (count > 0) {
                ans += s[i]; // If the count is greater than 0 (not the outermost closing parenthesis), add it to the result.
            }
        }
    }
    return ans; // Return the resulting string without the outermost parentheses.
}
};