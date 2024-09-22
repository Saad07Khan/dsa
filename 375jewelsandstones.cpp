class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>mp;
        int count=0;
        for(int i=0;i<stones.length();i++)
        {
            mp[stones[i]]++;
        }

        for(int i=0;i<jewels.length();i++)
        {
            if(mp.find(jewels[i])!=mp.end())
            {
                count+=mp[jewels[i]];
            }
        }
        return count;
    }
};