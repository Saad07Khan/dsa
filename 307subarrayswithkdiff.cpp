class Solution {
public:

    int atMost(vector<int>&nums, int goal)
    {
        map<int,int>mp;
        int i=0;
        int n=nums.size();
        int ans=0;
        int distinctCount=0;
        for(int j=0;j<n;j++)
        {
            if(mp[nums[j]]==0)
            {
                distinctCount++;
            }
            mp[nums[j]]++;

            while(distinctCount>goal)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    distinctCount--;
                }
                i++;
            }

            ans+=j-i+1;
        }

        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return atMost(nums,k) - atMost(nums,k-1);
    }
};