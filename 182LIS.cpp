class Solution
{
public:
    int f(int ind, int prevInd, int n, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (ind == n)
        {
            return 0;
        }
        if (dp[ind][prevInd + 1] != -1)
            return dp[ind][prevInd + 1];

        // not take
        int len = 0 + f(ind + 1, prevInd, n, nums, dp);
        if (prevInd == -1 || nums[ind] > nums[prevInd])
        {
            len = max(len, 1 + f(ind + 1, ind, n, nums, dp)); // curr ind becomes prevind
        }

        return dp[ind][prevInd + 1] = len;
    }

    // prevInd+1 is done to make a cordinate change so as to store -1

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, -1, n, nums, dp);
    }
};

// tabulation
class Solution {
public:

//second parameter will go in +1 state according cordinate shift
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prevInd=ind-1;prevInd>=-1;prevInd--)
            {
             int len = 0 + dp[ind+1][prevInd+1];
            if(prevInd==-1 || nums[ind]>nums[prevInd])
            {
            len = max(len,1+dp[ind+1][ind+1]); //curr ind becomes prevind
            }

             dp[ind][prevInd+1]=len;     
            }
        }
        return dp[0][-1+1];

        
    }
};

//space optimization
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>curr(n+1,0),ahead(n+1,0);

        for(int ind=n-1;ind>=0;ind--)
        {
            for(int prevInd=ind-1;prevInd>=-1;prevInd--)
            {
             int len = 0 + ahead[prevInd+1];
            if(prevInd==-1 || nums[ind]>nums[prevInd])
            {
            len = max(len,1+ahead[ind+1]); //curr ind becomes prevind
            }

             curr[prevInd+1]=len;     
            }

            ahead=curr;
        }
        return ahead[-1+1];

        
    }
};

//lis another dp approach
class Solution {
public:

    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n,1);
        int maxi=1;
        for(int i=1;i<n;i++)
        {
            for(int prev=0;prev<i;prev++)
            {
                if(nums[prev]<nums[i] && 1+dp[prev]>dp[i])
                {
                    dp[i]=1+dp[prev];
                }
            }
            maxi=max(maxi,dp[i]);
        }

        return maxi;
        
    }
};