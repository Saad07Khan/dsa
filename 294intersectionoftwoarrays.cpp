class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int,int>mp;
        vector<int>ans;
        if(n1<n2)
        {
            for(int i=0;i<n1;i++)
            {
                mp[nums1[i]]++;
            }

            for(int i=0;i<n2;i++)
            {
                if(mp.find(nums2[i])!=mp.end())
                {
                    mp[nums2[i]]--;
                    if(mp[nums2[i]]==0)
                    {
                        mp.erase(nums2[i]);
                    }
                    ans.push_back(nums2[i]);
                }
            }
        }
        else
        {
            for(int i=0;i<n2;i++)
            {
                mp[nums2[i]]++;
            }
            for(int i=0;i<n1;i++)
            {
                if(mp.find(nums1[i])!=mp.end())
                {
                    mp[nums1[i]]--;
                    if(mp[nums1[i]]==0)
                    {
                        mp.erase(nums1[i]);
                    }
                    ans.push_back(nums1[i]);
                }
            }
        }

        return ans;


    }
};