//recursion+memoization
class Solution {
public:

    int f(int i, int j, string &s1, string &s2, vector<vector<int>>&dp)
    {
        if(i==0 || j==0)
        {
            return 0;

        }

        if(dp[i][j]!=-1)return dp[i][j];

        if(s1[i-1]==s2[j-1]) return dp[i][j]= 1 + f(i-1,j-1,s1,s2,dp); //shifting indexes

        return dp[i][j] = max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
         vector<vector<int>> dp(n+1, vector<int>(m + 1, -1));//start from n,m index dp store +1
         return f(n,m,text1,text2,dp);

    }
};

//tabulation
class Solution {
public:

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
         vector<vector<int>> dp(n+1, vector<int>(m + 1, 0));//start from n,m index dp store +1

         for(int i=0;i<=n;i++) dp[i][0]=0; // go till <=lastindex as we shift index
         for(int j=0;j<=m;j++) dp[0][j]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1]) dp[i][j]= 1 + dp[i-1][j-1]; //shifting indexes

                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

            }
        }
         return dp[n][m];

    }
};

//space optimization
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
         int n=text1.length();
        int m=text2.length();
        vector<int>prev(m+1,0),curr(m+1,0);
      
        
         for(int j=0;j<=m;j++) prev[j]=0;

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1]) curr[j]= 1 + prev[j-1]; //shifting indexes

                else curr[j] = max(prev[j],curr[j-1]);

            }
            prev=curr;
        }

    
     return prev[m];
    }
};