
class Solution {
public:

    int maxDepth(string s) {
   
        int balanced = 0;
        
    
        int maxdepth = INT_MIN;

        for (int i = 0; i < s.length(); i++) {
            // Check if the current character is an opening parenthesis "(".
            if (s[i] == '(') {
                // If it is, increment the "balanced" variable to indicate an opening parenthesis.
                balanced++;
            }
            // Check if the current character is a closing parenthesis ")".
            else if (s[i] == ')') {
                // If it is, decrement the "balanced" variable to indicate a closing parenthesis.
                balanced--;
            }

            // Update the "maxdepth" variable to store the maximum value between the current "maxdepth" and "balanced."
            maxdepth = max(maxdepth, balanced);
        }

        // Return the maximum depth encountered in the input string.
        return maxdepth;
    }
};
