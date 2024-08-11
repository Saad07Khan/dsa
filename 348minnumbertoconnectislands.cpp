class Solution {
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        int n = grid.size();
        int m = grid[0].size();
        vis[x][y] = 1;
        for (int a = 0; a < 4; a++) {
            int nx = x + dx[a];
            int ny = y + dy[a];
            if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && grid[nx][ny]) {
                dfs(nx, ny, grid, vis);
            }
        }
    }

    int countIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j]) {
                    dfs(i, j, grid, vis);
                    islands++;
                }
            }
        }
        return islands;
    }

    int minDays(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = countIslands(grid);

        // If there are multiple islands or no islands, return 0.
        if (islands > 1 || islands == 0) {
            return 0;
        }

        // Check if removing a single land cell disconnects the island.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    grid[i][j] = 0;  // Temporarily remove the cell
                    islands = countIslands(grid);
                    grid[i][j] = 1;  // Restore the cell

                    if (islands > 1 || islands == 0) {
                        return 1;
                    }
                }
            }
        }

        // If the grid requires two steps to disconnect, return 2.
        return 2;
    }
};
