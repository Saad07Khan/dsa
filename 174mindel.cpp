class Solution
{
public:
    int lcs(string &text1, string &text2)
    {
        int n = text1.length();
        int m = text2.length();
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        for (int j = 0; j <= m; j++)
            prev[j] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (text1[i - 1] == text2[j - 1])
                    curr[j] = 1 + prev[j - 1]; // shifting indexes

                else
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            prev = curr;
        }

        return prev[m];
    }
    int minDistance(string word1, string word2)
    {
        int n = word1.length();
        int m = word2.length();

        return n + m - 2 * lcs(word1, word2);
    }
};