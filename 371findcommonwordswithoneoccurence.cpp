class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        

        int count=0;
        unordered_map<string,int>mp1;
        unordered_map<string,int>mp2;

        for(int i=0;i<words1.size();i++)
        {
            mp1[words1[i]]++;
        }

        for(int i=0;i<words2.size();i++)
        {
            mp2[words2[i]]++;
        }

        vector<string>ans;

        for(auto it: mp1)
        {
            if(it.second==1)
            {
                ans.push_back(it.first);
            }
        }

        for(int i=0;i<ans.size();i++)
        {
         
            for(auto it: mp2)
            {
                if(it.first==ans[i]&&it.second==1)
                {
                    count++;
                }
            }
        }

        return count;

        
    }
};