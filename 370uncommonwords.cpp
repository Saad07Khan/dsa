class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        stringstream ss1(s1);
        stringstream ss2(s2);

        unordered_map<string,int>mp;

        string word;
        while(ss1>>word)
        {
            mp[word]++;
        }
          while(ss2>>word)
        {
            mp[word]++;
        }

        vector<string>ans;
        for(auto it: mp)
        {
            if(it.second==1)
            {
                ans.push_back(it.first);
            }
        }

        return ans;

    }
};