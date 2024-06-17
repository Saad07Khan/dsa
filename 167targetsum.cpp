//recursion
#include <bits/stdc++.h>
int mod = (int)(1e9 + 7);
int findways(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)  //considering cases when 0 is in array
            return 2;// both can take or not take both possibilities
        if (target == arr[0] || target == 0)
            return 1; //can take in first case cannot take in second case so only 1 possibility
        return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];

    int not_take = findways(ind - 1, target, arr, dp);
    int take = 0;
    if (arr[ind] <= target)
        take = findways(ind - 1, target - arr[ind], arr, dp);

    return dp[ind][target] = (not_take + take) % mod;
}

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int n = nums.size();
        int totsum = 0;
        for (int i = 0; i < n; i++)
        {
            totsum += nums[i];
        }
        if (totsum - target < 0 || (totsum - target) % 2 != 0)
        {
            return 0;
        }
        int targ = (totsum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(targ + 1, 0));
        if (nums[0] == 0) // if nums[0] == 0 and target==0then u can either take or non take, both possibilities wont affect the result so take 2;
        {
            dp[0][0] = 2;
        }
        else
        {               
            dp[0][0] = 1;  //if target is 0 and index also zero then one possibility 1
        }
        if (nums[0] != 0 && nums[0] <= targ) 
        {
            dp[0][nums[0]] = 1; //if nums[0]!=0 then only 1 possibility ie take or not take
        }
        for (int ind = 1; ind < n; ind++)
        {
            int take = 0;
            for (int t = 0; t <= targ; t++)
            {
                int not_take = dp[ind - 1][t];
                if (nums[ind] <= t)
                {
                    take = dp[ind - 1][t - nums[ind]];
                }
                dp[ind][t] = not_take + take;
            }
        }
        return dp[n - 1][targ];
    }
};
