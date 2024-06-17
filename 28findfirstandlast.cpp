class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};

        // Find the first occurrence of target
        int low= 0;
        int high = nums.size() - 1;
        while (low<= high) {
            int mid = low+ (high - left) / 2;
            if (nums[mid] == target) {
                result[0] = mid;
                high = mid - 1;  // Continue searching on the lowside
            } else if (nums[mid] < target) {
                low= mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Find the last occurrence of target
        low= 0;
        high = nums.size() - 1;
        while (low<= high) {
            int mid = low+ (high - left) / 2;
            if (nums[mid] == target) {
                result[1] = mid;
                low= mid + 1;   // Continue searching on the high side
            } else if (nums[mid] < target) {
                low= mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};

