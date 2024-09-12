class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        //make a map of allowed
        set<char>mp;
        for(int i=0;i<allowed.length();i++)
        {
            mp.insert(allowed[i]);
        }
        int count=0;
        
        for(int i=0;i<words.size();i++)
        {
            string str=words[i];
            int count1=0;
            for(int j=0;j<str.length();j++)
            {
                if(mp.find(str[j])==mp.end())
                {
                    count1=0;
                }
                else
                {
                    count1++;
                }
            }

            if(count1==str.size())
            {
                count+=1;
            }
        }
        return count;
        
    }
};