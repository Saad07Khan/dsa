class Solution
{
public:
    int f(int i, int j, int initial, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 || vis[i][j] == 1 || grid[i][j] == 0)
        {
            return initial;
        }

        vis[i][j] = 1;
        initial += grid[i][j];

        int left = f(i + 1, j, initial, grid, vis);
        int right = f(i - 1, j, initial, grid, vis);
        int up = f(i, j + 1, initial, grid, vis);
        int down = f(i, j - 1, initial, grid, vis);
        vis[i][j] = 0;
        return max({left, right, up, down});
    }
    int getMaximumGold(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] != 0)
                {
                    vector<vector<int>> vis(n, vector<int>(m, 0));
                    int ans = f(i, j, 0, grid, vis);
                    maxi = max(maxi, ans);
                }
            }
        }

        return maxi;
    }
};