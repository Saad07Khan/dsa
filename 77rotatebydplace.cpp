class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Handle cases where k is greater than n
        k = k % n;
        
        reverse(nums.begin(), nums.end()); // Reverse the entire vector
        reverse(nums.begin(), nums.begin() + k); // Reverse the first k elements
        reverse(nums.begin() + k, nums.end()); // Reverse the remaining n-k elements
    }
};
