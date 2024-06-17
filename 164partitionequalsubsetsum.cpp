bool subsetSumToK(int n, int k, vector<int> &arr) {
    //  vector<vector<bool>>dp(n,vector<int>(k+1,0));
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false)); // intialize entire dp as false first

    for(int i=0;i<n;i++) dp[i][0]=true;

    if(arr[0]<=k)dp[0][arr[0]]=true;
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

class Solution {
public:
    bool canPartition(vector<int>& nums) {

        // divide the total sum into two parts, if totalsum even then if u can partition the array into one subset that is equal to half the sum that is enough
        //eg {2,5,8,11} totsum=26 halfsum=13
        int totsum=0;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            totsum+=nums[i];
        }

        if(totsum%2==1) return false;


        int target= totsum/2;

        return subsetSumToK(n,target,nums);
        
    }
};

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