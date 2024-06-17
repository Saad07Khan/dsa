// Define a class named "Solution."
class Solution {
public:
    // Declare a public member function named "romanToInt" that takes a string "s" as input and returns an integer.
    int romanToInt(string s) {
        // Create an unordered map "m" to store the Roman numeral characters as keys and their corresponding integer values.
        unordered_map<char, int> m;

        // Assign integer values to Roman numeral characters and store them in the map "m."
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        // Initialize a variable "ans" to 0 to store the final integer result.
        int ans = 0;

        // Start a loop that iterates through each character in the input string "s."
        for (int i = 0; i < s.length(); i++) {
            // Check if the current Roman numeral character has a smaller value than the next character.
            if (m[s[i]] < m[s[i + 1]]) {
                // If it does, subtract its value from the result "ans."
                ans -= m[s[i]];
            }
            else {
                // If it doesn't, add its value to the result "ans."
                ans += m[s[i]];
            }
        }

        // Return the final integer result, which represents the conversion of the Roman numeral string to an integer.
        return ans;
    }
};
//The key intuition lies in the fact that in Roman numerals, when a smaller value appears before a larger value, it represents subtraction, while when a smaller value appears after or equal to a larger value, it represents addition.
