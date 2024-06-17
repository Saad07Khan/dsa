#include <bits/stdc++.h> 
int f(int i, vector<int> &weight,vector<int>&value, int maxWeight,vector<vector<int>>&dp)
{
	if(i==0)
	{
		if(weight[0]<=maxWeight) return value[0];
		else
		return 0;
	}

	if(dp[i][maxWeight]!=-1)return dp[i][maxWeight];

	int notpick= 0+f(i-1,weight,value,maxWeight,dp);
	int pick= INT_MIN;
	if(weight[i]<=maxWeight)
	{
		pick= value[i] + f(i-1,weight,value,maxWeight-weight[i],dp);
	}

	return dp[i][maxWeight] = max(pick,notpick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,-1));
	return f(n-1,weight,value,maxWeight,dp);

}

//tabulation
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>>dp(n,vector<int>(maxWeight+1,0));

	for(int w=weight[0];w<=maxWeight;w++)
	{
		dp[0][w]=value[0];
	}

	for(int i=1;i<n;i++)
	{
		for(int w=0;w<=maxWeight;w++)
		{
			int notpick= 0+dp[i-1][w];
			int pick= INT_MIN;
			if(weight[i]<=w)
			{
				pick= value[i] + dp[i-1][w-weight[i]];
			}

			dp[i][w] = max(pick,notpick);
		}
	}
	return dp[n-1][maxWeight];

}


sc.nextLine().split("");