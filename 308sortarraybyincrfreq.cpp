class Solution {
public:

    static bool cmp(pair<int,int>&a, pair<int,int>&b)
    {
        if(a.second==b.second)
        {
            return a.first>b.first;
        }

        return a.second<b.second;
    }
    vector<int> frequencySort(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])!=mp.end())
            {
                pair<int,int>v=make_pair(nums[i],mp[nums[i]]);
                p.push_back(v);
            }
        }

        sort(p.begin(),p.end(),cmp);
        vector<int>ans;
        for(auto it: p)
        {
            ans.push_back(it.first);
        }
        return ans;
    }
};