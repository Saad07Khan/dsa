class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;

        int majo= nums.size()/3;

        for(int i=0;i<nums.size();i++)
        {
            // int ans=nums[i];
            // mp[ans]++;
            
            
            mp[nums[i]]++;
        }

        for(auto a : mp)
        {
            if(a.second>majo)
            {
                ans.push_back(a.first);

            }
        }

        return ans;



        
    }
};