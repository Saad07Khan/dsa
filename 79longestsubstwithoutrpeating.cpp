class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {

        set<char> st;

        int maxi = 0;

        int n = s.size();

        int start = 0;
        int end = 0;

        while (start < n && end < n)
        {
            // auto it=st.find(s[start]);
            if (st.find(s[start]) == st.end())
            {
                if (start - end + 1 > maxi)
                {
                    maxi = start - end + 1;
                }
                st.insert(s[start]);
                start++;
            }

            else
            {
                st.erase(s[end]);
                end++;
            }
        }

        return maxi;
    }
};
