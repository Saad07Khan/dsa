class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>>q;
        set<string>st(bank.begin(),bank.end());
        q.push({startGene,0});
        st.erase(startGene);
        while(!q.empty())
        {
            string word = q.front().first;
            int mutations=q.front().second;
            q.pop();
            if(word==endGene)
            {
                return mutations;
            }
            for(int i=0;i<word.length();i++)
            {
                char original=word[i];
                for(char ch='A';ch<='Z';ch++)
                {
                    word[i]=ch;
                    if(st.find(word)!=st.end())
                    {
                        q.push({word,mutations+1});
                        
                        st.erase(word);
                    }
                }
                word[i]=original;
            }
            
        }
        return -1;
        
    }
};