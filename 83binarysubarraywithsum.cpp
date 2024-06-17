class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        map<int,int>mp;

        mp[0]=1;
        int prefix=0;
        int count=0;

        for(int i=0;i<nums.size();i++)
        {
            prefix+=nums[i];

            if(mp.find(prefix-goal)!=mp.end())
            {
                count+=mp[prefix-goal];
            }

            mp[prefix]++;

        }
        return count;
        
    }
};