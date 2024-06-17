class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int>mp;
        vector<string>ans;
        if(s.length()<=10)
        {
            return ans;
        }
        for(int i=0;i<=s.length()-10;i++)
        {
            string h = s.substr(i,10);
            mp[h]++;

        }
        for(auto it: mp)
        {
            if(it.second>1)
            {
                ans.push_back(it.first);
            }
        }

        return ans;
        
    }
};