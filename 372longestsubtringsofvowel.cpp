class Solution {
public:
    int longestBeautifulSubstring(string nums) {
        
        map<char,int>mp;
        int maxi=0;
        int i=0;
        int n= nums.length();
        for(int j=0;j<n;j++)
        {
            mp[nums[j]]++;
            while(i<j && nums[j]-'0'<nums[j-1]-'0')
            {
                
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                }

                i++;
            }

            if(mp.size()==5)
            {
                maxi=max(maxi,j-i+1);
            }
        }

        return maxi;
    }
};