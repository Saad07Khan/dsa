class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int maxi = 1;
        int lastindex = 0;
        vector<int> dp(n, 1), hash(n);
        for (int i = 0; i < n; i++)
        {
            hash[i] = i;
            for (int prevind = 0; prevind < i; prevind++)
            {
                if (nums[i] % nums[prevind] == 0 && 1 + dp[prevind] > dp[i])
                {
                    dp[i] = 1 + dp[prevind];
                    hash[i] = prevind; // stores the indice it came from
                }
            }

            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastindex = i;
            }
        }
        vector<int> temp;
        temp.push_back(nums[lastindex]);

        while (hash[lastindex] != lastindex)
        {
            lastindex = hash[lastindex];
            temp.push_back(nums[lastindex]);
        }
        return temp;
    }
};