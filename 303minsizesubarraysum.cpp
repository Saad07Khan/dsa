class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int ans=INT_MAX;
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=nums[j];
            while(sum>=target)
            {
               ans=min(ans,j-i+1);
               sum-=nums[i];
               i++;
            }
           
        }
        if(ans!=INT_MAX)
        {
            return ans;
        }
        else
        {
            return 0;
        }
        
    }
};