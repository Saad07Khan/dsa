// keep the longestpalindromicsubseq intact and remaining u add in front and back after reversing it, so to the insertions required would be length of total string - length of longest common palindromic subseq(since it is being kept intact)

class Solution
{
public:
    int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (i == 0 || j == 0)
        {
            return 0;
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i - 1] == s2[j - 1])
            return dp[i][j] = 1 + f(i - 1, j - 1, s1, s2, dp);

        return dp[i][j] = max(f(i - 1, j, s1, s2, dp), f(i, j - 1, s1, s2, dp));
    }
    int longestPalindromeSubseq(string &s)
    {
        int n = s.length();

        string t = s;
        reverse(t.begin(), t.end());
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        return f(n, m, s, t, dp);
    }
    int minInsertions(string s)
    {
        int n = s.length();
        return n - longestPalindromeSubseq(s);
    }
};