class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans = ""; // Initialize an empty string to store the longest common prefix.
        
        // Sort the vector of strings lexicographically.
        sort(v.begin(), v.end());

        int n = v.size(); // Get the number of strings in the vector.
        string first = v[0]; // Get the first string (smallest) after sorting.
        string last = v[n - 1]; // Get the last string (largest) after sorting.

        // Loop through the characters of the first and last strings.
        for (int i = 0; i < min(first.size(), last.size()); i++) {
            if (first[i] != last[i]) {
                return ans; // If a character mismatch is found, return the current common prefix.
            }
            ans += first[i]; // Append the matching character to the common prefix.
        }

        return ans; // Return the longest common prefix found.
    }
};
// Sorting the strings lexicographically simplifies finding the longest common prefix among multiple strings. It groups similar strings with common prefixes together in the sorted order, reducing the need for character comparisons. By comparing only the first and last strings in the sorted order, we efficiently find the longest common prefix, as it must be a prefix of both the smallest and largest strings. This optimization reduces the number of character comparisons, making the algorithm more efficient than comparing all characters in all strings individually.