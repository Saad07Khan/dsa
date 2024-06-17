// recursion+memoization
class Solution
{
public:
    int f(int i, int buy, int n, vector<int> &prices, vector<vector<int>> &dp)
    {

        if (i == n)
        {
            return 0; // since cant get anymore money
        }

        if (dp[i][buy] != -1)
            return dp[i][buy];
        int profit = 0;
        if (buy != 0) // if buy is allowed u have 2 choices
        {
            profit = max(-prices[i] + f(i + 1, 0, n, prices, dp), 0 + f(i + 1, 1, n, prices, dp));
            // buy now and in next indcannot buy only sell   //dont buy now, next ind can buy
        }
        else
        {
            profit = max(prices[i] + f(i + 1, 1, n, prices, dp), 0 + f(i + 1, 0, n, prices, dp));
            // stock sold and next ind can buy   // stock not sold so next ind cant buy only sell
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
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][0] = dp[n][1] = 0; // for any value of buy

        for (int i = n - 1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy != 0) // if buy is allowed u have 2 choices
                {
                    profit = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);
                    // buy now and in next indcannot buy only sell   //dont buy now, next ind can buy
                }
                else
                {
                    profit = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
                    // stock sold and next ind can buy   // stock not sold so next ind cant buy only sell
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};

//space optimization
class Solution
{
public:
 
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<int>curr(2,0),prev(2,0);

        curr[0] = curr[1] = 0; 

        for (int i = n-1; i >= 0; i--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;
                if (buy != 0) 
                {
                    profit = max(-prices[i] + prev[0], 0 + prev[1]);

                }
                else
                {
                    profit = max(prices[i] + prev[1], 0 + prev[0]);
                }
                curr[buy] = profit;
            }
            prev=curr;
        }


        return prev[1];
    }
};

