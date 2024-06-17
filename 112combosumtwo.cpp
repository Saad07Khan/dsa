class Solution
{
public:
    void solve(int index, int n, int k, vector<vector<int>> &ans, vector<int> &temp)
    {
        if (n == 0 && k == 0)
        {
            ans.push_back(temp);
            return;
        }
        if (k == 0)
            return;

        for (int i = index; i <= 9; i++)
        {
            temp.push_back(i);
            solve(i + 1, n - i, k - 1, ans, temp);
            temp.pop_back();
        }
        // return;
    }

    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(1, n, k, ans, temp);
        return ans;
    }
};
