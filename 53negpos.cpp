// Define a class named "Solution."
class Solution {
public:
    // Declare a public member function named "rearrangeArray" that takes a vector of integers "nums" as input and returns a vector of integers.
    vector<int> rearrangeArray(vector<int>& nums) {
        // Get the size of the input vector "nums" and store it in the variable "n."
        int n = nums.size();
        
        // Create a new vector "ans" of the same size as "nums" and initialize all elements to 0.
        vector<int> ans(n, 0);

        // Initialize two index variables, "posindex" for positive numbers and "negindex" for negative numbers, both starting at different positions.
        int posindex = 0;
        int negindex = 1;

        // Start a loop that iterates through each element of the input vector "nums."
        for (int i = 0; i < nums.size(); i++) {
            // Check if the current element "nums[i]" is negative.
            if (nums[i] < 0) {
                // If it is negative, place it in the "ans" vector at the "negindex" position and increment "negindex" by 2 to ensure a gap between negative numbers.
                ans[negindex] = nums[i];
                negindex += 2;
            } else {
                // If it is not negative (positive or zero), place it in the "ans" vector at the "posindex" position and increment "posindex" by 2 to ensure a gap between positive numbers.
                ans[posindex] = nums[i];
                posindex += 2;
            }
        }
        // Return the rearranged vector "ans" that alternates between positive and negative numbers.
        return ans;
    }
};
