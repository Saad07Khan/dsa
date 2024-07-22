class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        map<int,int>mp;
        int i=0;
        int ans=0;
        int sum=0;
        for(int j=0;j<n;j++)
        {
            sum+=nums[j];
            mp[nums[j]]++;
            while(mp[nums[j]]>1)
            {
                sum-=nums[i];
                mp[nums[i]]--;
                i++;
            }
            ans=max(ans,sum);
        }
        return ans;

        
        
    }
};