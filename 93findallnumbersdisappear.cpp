class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {

        unordered_map<int, int> mp;
        vector<int> v;

        for (int i = 0; i < nums.size(); i++)
        {
            mp[nums[i]]++;
        }

        for (int i = 1; i <= nums.size(); i++)
        {
            if (mp.find(i) == mp.end())
            {
                v.push_back(i);
            }
        }

        return v;
    }
};