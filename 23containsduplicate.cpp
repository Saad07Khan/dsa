class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int n = nums.size();
        int low=0;
        int high= n-1;

        for(int i=0;i<n;i++)
        {
        while(low<=high)
        {
            if(nums[low]==nums[high])
            {
                if((abs(high-low)<=k))
                {
                    return true;
                    
                }
                // low++;
                // else
                // {
                //     return false;
            // }
            }
            low++;
            // high--;
        }
        high--;
        }

        return false;
        
    }
};


// new soln
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n && j <= i + k; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }

        return false;
    }
};
