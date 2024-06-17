#include <bits/stdc++.h>
int mod = (int)(1e9 + 7);
int findways(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && arr[0] == 0)  //considering cases when 0 is in array
            return 2;// both can take or not take both possibilities
        if (target == arr[0] || target == 0)
            return 1; //can take in first case cannot take in second case  so only 1 possibility
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
int countPartitions(int n, int d, vector<int> &arr)
{
    int totsum = 0;
    for (int i = 0; i < n; i++)
    {
        totsum += arr[i];
    }
    if (totsum - d < 0 || (totsum - d) % 2 != 0)
        return false;
    int target = (totsum - d) / 2;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    return findways(n - 1, target, arr, dp);
}
