//recursion and memoization
class Solution {
public:
    int f(int index, vector<int>&coins, int amount, vector<vector<int>>&dp)
    {
        if(index==0)
        {
            if(amount%coins[0]==0) return amount/coins[0]; // if coins divisible by amount then only take them
            return 1e9; 
        }

        if(dp[index][amount]!=-1) return dp[index][amount];

        int notpick = 0 + f(index-1,coins,amount,dp);
        int pick = INT_MAX;
        if(coins[index]<=amount)
        {
        pick = 1 + f(index,coins,amount-coins[index],dp);
        }
        return dp[index][amount] = min(notpick,pick);

    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,coins,amount,dp);
        if(ans>=1e9)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};

//tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int target = 0; target <= amount; i++) { // target can be anything from 0 to amount
            if (target % coins[0] == 0) {
                dp[0][target] = target / coins[0];
            } else {
                dp[0][target] = 1e9;
            }
        }

        for (int ind = 1; ind < n; ind++) { // index from 1 to n-1 as we started recursion from n-1 to 0
            int take = INT_MAX;  // Move this outside the inner loop
            for (int target = 0; target <= amount; target++) { //we go from initial target to 0, go opposite
                int nottake = 0 + dp[ind - 1][target];
                if (coins[ind] <= target) {
                    take = 1 + dp[ind][target - coins[ind]];
                }

                dp[ind][target] = min(nottake, take);
            }
        }

        int ans = dp[n - 1][amount];
        if (ans >= 1e9) return -1;
        return ans;
    }
};
