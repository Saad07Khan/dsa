// 0-based indexing
// recursion+memoization
class Solution
{
public:
    int f(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if (j == 0) // this base case shud be first as 2nd string always smaller than 1st
        {
            return 1;
        }
        if (i == 0)
        {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i - 1] == t[j - 1])
        {
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp); //two possibilites
        }
        else
        {
            return dp[i][j] = f(i - 1, j, s, t, dp);
        }
    }
    int numDistinct(string s, string t)
    {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return f(n, m, s, t, dp);
    }
};

// tabulation

class Solution
{
public:
    int numDistinct(string s, string t)
    {

        int n = s.length();
        int m = t.length();
        vector<vector<double>> dp(n + 1, vector<double>(m + 1, 0));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int j = 1; j <= m; j++)
            dp[0][j] = 0; // starting from 1 since 0 value of j already covered above

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return (int)dp[m][n];
    }
};

//space optimization
   int numDistinct(string s, string t)
    {

        int n = s.length();
        int m = t.length();
        vector<double>prev(m+1,0),curr(m+1,0);

        prev[0]=curr[0]=1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i - 1] == t[j - 1])
                {
                    curr[j] = prev[j - 1] + prev[j];
                }
                else
                {
                    curr[j] = prev[j];
                }
            }
            prev=curr;
        }

        return (int)prev[m];
    }