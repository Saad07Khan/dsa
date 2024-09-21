class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        int mini=INT_MAX;
        int ans=0;
        for(int j=0;j<n-1;j++)
        {
            for(int i=j+1;i<n;i++)
            {
                if(cards[j]==cards[i])
                {
                     ans=i-j+1;
                   mini=min(ans,mini);
                }
           

               
            }
        }

        if(mini!=INT_MAX)
        {
            return mini;
        }
        else
        {
            return -1;
        }
    }
};


class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n=cards.size();
        int ans=INT_MAX;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(mp.find(cards[i])!=mp.end())
            {
                ans=min(ans,i-mp[cards[i]]+1);
            }
            mp[cards[i]]=i;
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};