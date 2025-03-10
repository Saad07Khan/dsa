//recursion+memoization
class Solution
{
public:
    int f(int i, int buy, int cap, int n, vector<int> &prices, vector<vector<vector<int>>> &dp)
    {

        if (i == n || cap == 0)
        {
            return 0;
        }

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        int profit = 0;
        if (buy != 0)
        {
            profit = max(-prices[i] + f(i + 1, 0, cap, n, prices, dp), 0 + f(i + 1, 1, cap, n, prices, dp));
        }
        else
        {
            profit = max(prices[i] + f(i + 1, 1, cap - 1, n, prices, dp), 0 + f(i + 1, 0, cap, n, prices, dp));
        }

        return dp[i][buy][cap] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return f(0, 1, 2, n, prices, dp);
    }
};
//tabulation