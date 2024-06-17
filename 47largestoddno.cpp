class Solution {
public:
    string largestOddNumber(string num) {
        int last = -1; // Initialize a variable 'last' to store the index of the last odd digit.

        for (int i = 0; i < num.size(); i++) { // Loop through the characters in the 'num' string.
            if (num[i] % 2 != 0) { // Check if the current character is an odd digit (not divisible by 2).
                last = i; // Update 'last' to the index of the current character (last odd digit found).
            }
        }

        if (last != -1) { // If at least one odd digit was found in the string.
            return num.substr(0, last + 1); // Return a substring from the start of 'num' to the last odd digit (since if last digit is odd the entire number is odd)
        } else {
            return ""; // If no odd digits were found in the string, return an empty string.
        }
    }
};
