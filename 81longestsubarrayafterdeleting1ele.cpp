class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {

        int n = nums.size();
        int i = 0;
        int j = 0;
        int count = 0;
        int maxi = 0;

        while (i < n)
        {
            if (nums[i] == 0)
            {
                count++;
            }

            while (count > 1)
            {
                if (nums[j] == 0)
                {
                    count--;
                    j++;
                }
                else
                {
                    j++;
                }
            }

            maxi = max(maxi, i - j);
            i++;
        }
        return maxi;
    }
};
// The time complexity is not O(n^2) because the code only iterates through the input vector once, which is a linear operation. Each element in the array is processed at most twice (once when it's examined by i and once when it's examined by j), but this doesn't lead to a quadratic time complexity.