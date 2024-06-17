class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int minElement = nums[0];
        int maxDiff = -1; // Initialize to -1 to indicate no valid difference

        for (int i = 1; i < n; i++) {
            if (nums[i] > minElement) {
                maxDiff = max(maxDiff, nums[i] - minElement);
            }
            minElement = min(minElement, nums[i]);
        }

        return maxDiff;
        int maxloop;
        int no;
    }
};
