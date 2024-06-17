
int mod = (int)(1e9+7);
int f(int ind, int target, vector<int>&arr,vector<vector<int>>&dp)
{

	if(target==0)return 1; // no need to go until last index and check
	if(ind==0)
	{
		if(arr[0]==target)return 1;
		return 0;
	}

	if(dp[ind][target]!=-1)return dp[ind][target];
	int nottake = f(ind-1,target,arr,dp);
	int take=0;

	if(arr[ind]<=target)
	take = f(ind-1,target-arr[ind],arr,dp);

	return dp[ind][target]= (take+nottake)%mod;
}
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+ 1, -1));
	return f(n-1,k,arr,dp);
}
