class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {

        int count = 0;
        int pre = 0;
        map<int, int> mp;
        mp[0] = 1;
// this is done for the test case
// Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2  do dry run and check
// Output: 16
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2 == 0)
            {
                nums[i] = 0;
            }

            else if (nums[i] % 2 != 0)
            {
                nums[i] = 1;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            pre += nums[i];

            if (mp.find(pre - k) != mp.end())
            {
                count += mp[pre - k];
            }

            mp[pre]++;
        }
        return count;
    }
};
