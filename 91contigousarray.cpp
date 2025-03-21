// Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {

        unordered_map<int, int> mp;

        mp[0] = -1;

        int sum = 0;
        int maxlen = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                sum += -1;
            }
            else if (nums[i] == 1)
            {
                sum += 1;
            }

            if (mp.find(sum) != mp.end())
            {
                maxlen = max(maxlen, i - mp[sum]);
            }

            else
            {
                mp[sum] = i;
            }
        }

        return maxlen;
    }
};