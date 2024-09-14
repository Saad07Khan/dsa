class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //edge case 1st and last element
        //Find longest consecutive length of the maximum element of nums."
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
        }
        int count=1;
        int tempcount=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==maxi)
            {
                tempcount++;
            }
            else
            {
                count= max(count,tempcount);
                tempcount=0;
            }
        }
        
        count = max(count,tempcount);
        return count;
    }
};