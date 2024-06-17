class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {

        int n = nums.size();

        if (n == 0)
            return 0;
        int longest = 1;

        unordered_set<int> st;

        // unordered set does not contain duplicate elements

        for (int i = 0; i < n; i++) // inserting all elements of the array into the set
        {
            st.insert(nums[i]);
        }

        for (auto it : st)
        {
            if (st.find(it - 1) == st.end()) // checking if you are the first element your previous element will not be in the set as we are reaching the end of the set
            {
                int cnt = 1;
                int x = it;
                while (st.find(x + 1) != st.end()) // checking the consecutive numbers
                {
                    x = x + 1;
                    cnt = cnt + 1;
                }

                longest = max(longest, cnt);
            }
        }

        return longest;
    }
};