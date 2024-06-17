// recursion + memoization
class Solution
{
public:
    int f(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (ind == 0)

        {
            if(amount%coins[0]==0)
            {
                return (int)(amount/coins[0]);
            }
            else
            {
                return 0;
            }
            // return (amount % coins[0] == 0);
        }

        if (dp[ind][amount] != -1)
            return dp[ind][amount];
        int nottake = f(ind - 1, amount, coins, dp);
        int take = 0;
        if (coins[ind] <= amount)
            take = f(ind, amount - coins[ind], coins, dp);
        return dp[ind][amount] = nottake + take;
    }
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, amount, coins, dp);
    }
};
// tabulation
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int amt = 0; amt <= amount; amt++)
        {
            dp[0][amt] = (amt % coins[0] == 0);
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int amt = 0; amt <= amount; amt++)
            {
                int nottake = dp[ind - 1][amt];
                int take = 0;
                if (coins[ind] <= amt)
                    take = dp[ind][amt-coins[ind]];
                dp[ind][amt] = nottake + take;
            }
        }
        return dp[n - 1][amount];
    }
};