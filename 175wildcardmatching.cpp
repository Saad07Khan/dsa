class Solution {
public:
// 0 based indexing
    int f(int i, int j, string &text, string &pattern, vector<vector<int>>&dp)
    {
        if(i<0 && j<0)
        {
            return true;
        }
        if(i<0 && j>=0)  // if pattern consists of asteriks only since it matches empty subseq also
        {
            for(int k=0;k<=j;k++)
            {
                if(pattern[k]!='*')return false;
            }
            return true;
        }
        if(i>=0 && j<0)
        {
            return false;
        }

        if(dp[i][j]!=-1)return dp[i][j];

        if(text[i]==pattern[j]||pattern[j]=='?')
        {
            return dp[i][j]= f(i-1,j-1,text,pattern,dp);
        }
        if(pattern[j]=='*')
        {
                            //star stays                  //star moves
            return dp[i][j]= f(i-1,j,text,pattern,dp)|| f(i,j-1,text,pattern,dp);
        }
        return dp[i][j]=false; //nothing matches
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
        
    }
};

// convert into 1based indexing to make it easier to code tabulation
class Solution {
public:

    int f(int i, int j, string &text, string &pattern, vector<vector<int>>&dp)
    {

        if(i==0 && j==0)
        {
            return true;
        }

        if(i==0 && j>0)  
        {
            for(int k=0;k<j;k++)
            {
                if(pattern[k]!='*')return false;
            }
            return true;
        }

        if(i>0 && j==0)
        {
            return false;
        }

        if(dp[i][j]!=-1)return dp[i][j];

        if(text[i-1]==pattern[j-1]||pattern[j-1]=='?')
        {
            return dp[i][j]= f(i-1,j-1,text,pattern,dp);
        }
        if(pattern[j-1]=='*')
        {
            return dp[i][j]= f(i-1,j,text,pattern,dp)|| f(i,j-1,text,pattern,dp);
        }
        return dp[i][j]=false; //nothing matches
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,p,dp);
        
    }
};