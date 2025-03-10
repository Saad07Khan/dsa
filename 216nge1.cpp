class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {

        unordered_map<int, int> mp;
        vector<int> ans;
        stack<int> st;
        int n = nums2.size();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && st.top() <= nums2[i % n])
            {
                st.pop();
            }

            if (st.empty())
            {
                mp[nums2[i]] = -1;
            }
            else
            {
                mp[nums2[i]] = st.top();
            }

            st.push(nums2[i]);
        }

        for (int i = 0; i < nums1.size(); i++)
        {
            int ele = nums1[i];
            if (mp.find(ele) != mp.end())
            {
                ans.push_back(mp[nums1[i]]);
            }
        }

        return ans;
    }
};
