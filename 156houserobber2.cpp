class Solution
{
public:
    int f(int index, vector<int> &nums, vector<int> &dp)
    {
        if (index == 0)
            return nums[index];
        if (index < 0)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int pick = nums[index] + f(index - 2, nums, dp);
        int notpick = 0 + f(index - 1, nums, dp);

        return dp[index] = max(pick, notpick);
    }

    int rob(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> temp1;
        vector<int> temp2;
        if (n == 1)
        {
            return nums[0];
        }

        for (int i = 0; i < n; i++)
        {
            if (i != 0)
                temp1.push_back(nums[i]);
            if (i != n - 1)
                temp2.push_back(nums[i]);
        }
        vector<int> dp1(n - 1, -1);
        vector<int> dp2(n - 1, -1);
        return max(f(n - 2, temp1, dp1), f(n - 2, temp2, dp2));
    }
};