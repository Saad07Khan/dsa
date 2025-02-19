//recursion and memoization
#include <bits/stdc++.h> 

bool f(int ind, int target,vector<int> &arr,vector<vector<int>>&dp )
{
    if(target==0) return true;
    if(ind==0)
    return (arr[0]==target);
    if(dp[ind][target]!=-1)return  dp[ind][target];

    bool notpick = f(ind-1,target,arr,dp);
    bool pick=false;
    if(arr[ind]<=target)
    pick = f(ind-1,target-arr[ind],arr,dp);

    return dp[ind][target] = pick|notpick;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    return f(n-1,k,arr,dp);
}

//tabulation
#include <bits/stdc++.h> 
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    //  vector<vector<bool>>dp(n,vector<int>(k+1,0));
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false)); // intialize entire dp as false first

    for(int i=0;i<n;i++) dp[i][0]=true;

    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=k;target++)
        {
            bool notTake = dp[ind-1][target];
            bool take = false;
            if(arr[ind]<=target) take = dp[ind-1][target-arr[ind]];
            dp[ind][target]= take|notTake;
        }
    }

    return dp[n-1][k];
}