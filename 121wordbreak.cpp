class Solution {
public:

int dp[301];
int solve(int i, string s, set<string>&st)
{
    if(i==s.size())
    {
        return 1;
    }
    string temp;
    if(dp[i]!=-1)return dp[i];
    for(int j=i;j<s.size();j++)
    {
        temp+=s[j];
        if(st.find(temp)!=st.end())
        {
            if(solve(j+1,s,st))return dp[i]=1;
        }
    }
    return dp[i]=0;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        for(auto a:wordDict)
        {
            st.insert(a);
        }
        memset(dp,-1,sizeof dp);

        return solve(0,s,st);
        
    }
};




