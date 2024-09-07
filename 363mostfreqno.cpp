class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==key)
            {
                mp[nums[i+1]]++;
            }
        }

        int maxi=0;
        for(auto it: mp)
        {
            maxi=max(maxi,it.second);
        }
        int ans;
        for(auto it: mp)
        {
            if(maxi==it.second)
            {
                ans=it.first;
            }
        }
        return ans;
    }
};

