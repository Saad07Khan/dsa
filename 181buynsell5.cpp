class Solution
{
public:
    int f(int i, int buy, int n, vector<int> &prices, vector<vector<int>> &dp)
    {

        if (i >= n) // >=n bcuz we go i+2 as well 
        {
            return 0; // since cant get anymore money
        }

        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if (buy != 0) 
        {
            profit = max(-prices[i] + f(i + 1, 0, n, prices, dp), 0 + f(i + 1, 1, n, prices, dp));
        
        }
        else
        {
            profit = max(prices[i] + f(i + 2, 1, n, prices, dp), 0 + f(i + 1, 0, n, prices, dp));
                                        //cooldown
        }

        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return f(0, 1, n, prices, dp);
    }
};

// tabulation
class Solution
{
public:
  
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<vector<int>> dp(n+2, vector<int>(2, 0)); //n+2 as dp[i+2] will be computed

        for (int i = n-1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy != 0) 
                {
                    profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);

                }
                else
                {
                    profit = max(prices[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
                 }

                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};