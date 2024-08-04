class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int>mp;
        int i=0;
        int maxi=0;
        for(int j=0;j<n;j++)
        {
            mp[nums[j]]++;
            while(i<=j && mp[nums[j]]>k)
            {
                mp[nums[i]]--;
                i++;
            }

            maxi=max(maxi,j-i+1);

        }
        return maxi;
        
    }
};