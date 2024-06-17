class Solution
{
public:
    void dfs(int r, int c, vector<vector<int>> &grid, vector<vector<int>> &vis, int row[], int col[])
    {
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < 4; i++)
        {
            int ij = r + row[i];
            int cj = c + col[i];
            if (ij >= 0 && ij < n && cj >= 0 && cj < m && grid[ij][cj] == 1 && vis[ij][cj] != 1)
            {
                dfs(ij, cj, grid, vis, row, col);
            }
        }
    }
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int row[] = {-1, 0, +1, 0};
        int col[] = {0, 1, 0, -1};
        int count = 0;
        for (int j = 0; j < m; j++)
        {
            if (grid[0][j] == 1 && vis[0][j] != 1)
            {
                dfs(0, j, grid, vis, row, col);
            }
            if (grid[n - 1][j] == 1 && vis[n - 1][j] != 1)
            {
                dfs(n - 1, j, grid, vis, row, col);
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 1 && vis[i][0] != 1)
            {
                dfs(i, 0, grid, vis, row, col);
            }
            if (grid[i][m - 1] == 1 && vis[i][m - 1] != 1)
            {
                dfs(i, m - 1, grid, vis, row, col);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1 && vis[i][j] != 1)
                {
                    count++;
                }
            }
        }

        return count;
    }
};