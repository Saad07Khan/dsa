class Solution
{
public:
    void dfs1(int r, int c, vector<vector<char>> &board, vector<vector<int>> &vis, int n, int m, int row[], int col[])
    {

        vis[r][c] = 1;
        for (int i = 0; i < 4; i++)
        {
            int ij = r + row[i];
            int cj = c + col[i];
            if (ij >= 0 && ij < n && cj >= 0 && cj < m && vis[ij][cj] != 1 && board[ij][cj] == 'O')
            {
                dfs1(ij, cj, board, vis, n, m, row, col);
            }
        }
    }
    void solve(vector<vector<char>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        int row[] = {-1, 0, +1, 0};
        int col[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++)
        {
            if (!vis[0][j] && board[0][j] == 'O')
            {
                dfs1(0, j, board, vis, n, m, row, col);
            }
            if (!vis[n - 1][j] && board[n - 1][j] == 'O')
            {
                dfs1(n - 1, j, board, vis, n, m, row, col);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i][0] && board[i][0] == 'O')
            {

                dfs1(i, 0, board, vis, n, m, row, col);
            }
            if (!vis[i][m - 1] && board[i][m - 1] == 'O')
            {
                dfs1(i, m - 1, board, vis, n, m, row, col);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == 'O' && vis[i][j] != 1)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};