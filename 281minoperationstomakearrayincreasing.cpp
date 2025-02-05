class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (nums[i] < nums[i + 1])
                continue;
            else
            {
                int diff = nums[i] - nums[i + 1] + 1;
                nums[i + 1] = nums[i + 1] + diff;
                count += diff;
            }
        }
        return count;
    }
};