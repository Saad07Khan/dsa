class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {

        int i = 0;
        int j = 0;
        int n = nums.size();
        int count = 0;
        int maxi = INT_MIN;

        while (i < n)
        {
            if (nums[i] == 0)
            {
                count++;
            }

            while (count > k)
            {

                if (nums[j] == 0)
                {
                    count--;
                }
                j++;
            }

            maxi = max(maxi, i - j + 1);
            i++;
        }
        return maxi;
    }
};