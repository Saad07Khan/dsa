
class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {

        int i = 0;
        int j = 0;
        int count = 0;
        int n = g.size(), m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while (i < n && j < m)
        {
            if (s[j] >= g[i])
            {
                count++;
                i++;
            }
            j++;
        }

        return count;
    }
};