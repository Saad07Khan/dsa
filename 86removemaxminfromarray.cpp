class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {

        int mini = nums[0];
        int maxele = nums[0];
        int maxind = 0;
        int minind = 0;
        int n = nums.size();

        if (nums.size() == 1)
        {
            return 1;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (mini < nums[i])
            {
                mini = nums[i];
                minind = i;
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (maxele > nums[i])
            {
                maxele = nums[i];
                maxind = i;
            }
        }

        int x = min(minind, maxind);
        int y = max(minind, maxind);

        int ans = min({n - (y - x - 1), y + 1, n - x}); // formula to get correct indices
        return ans;
    }
};