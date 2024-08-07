class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string>ans;
        for(string s: queries)
        {
            for(string str: dictionary)
            {
                int count=0;
                for(int i=0;i<s.size();i++)
                {
                    if(str[i]!=s[i])
                    {
                        count++;
                    }
                }
                if(count<=2)
                {
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;

    }
};