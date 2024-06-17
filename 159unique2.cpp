// recursion
class Solution
{
public:
    int f(vector<vector<int>> &obstacleGrid, int m, int n)
    {
        if (m == 0 && n == 0)
        {
            return 1;
        }

        if (m < 0 || n < 0 || obstacleGrid[m][n] == 1)
        {
            return 0;
        }

        int up = f(obstacleGrid, m - 1, n);
        int left = f(obstacleGrid, m, n - 1);

        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        return f(obstacleGrid, m - 1, n - 1);
    }
};

// memoization
class Solution
{
public:
    int f(vector<vector<int>> &obstacleGrid, int m, int n, vector<vector<int>> &dp)
    {
        if (m >= 0 && n >= 0 && obstacleGrid[m][n] == 1) // if its a valid cell and if it is dead return 0
        {
            return 0;
        }
        if (m == 0 && n == 0)
        {
            return 1;
        }

        if (m < 0 || n < 0)
        {
            return 0;
        }
        if (dp[m][n] != -1)
            return dp[m][n];

        int up = f(obstacleGrid, m - 1, n, dp);
        int left = f(obstacleGrid, m, n - 1, dp);

        return dp[m][n] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return f(obstacleGrid, m - 1, n - 1, dp);
    }
};

// tabulation
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[i][j] = 1;
            else
            {
                int up;
                int left;
                if (i > 0)
                {
                    up = dp[i - 1][j];
                }
                else
                {
                    up = 0;
                }
                if (j > 0)
                {
                    left = dp[i][j - 1];
                }
                else
                {
                    left = 0;
                }
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}
}
;