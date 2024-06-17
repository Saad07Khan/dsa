// recursion+memoization
int f(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return price[0] * N; // since only 1 element in array
    }

    if (dp[ind][N] != -1)
        return dp[ind][N];

    int nottake = 0 + f(ind - 1, N, price, dp);
    int take = INT_MIN;
    int rodlength = ind + 1;
    if (rodlength <= N)
        take = price[ind] + f(ind, N - rodlength, price, dp);

    return dp[ind][N] = max(take, nottake);
}

int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return f(n - 1, n, price, dp);
}

// tabulation
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    for (int N = 0; N <= n; N++)
    {
        dp[0][N] = price[0] * N;
    }

    for (int ind = 1; ind < n; ind++)
    {
        int take = INT_MIN;
        for (int N = 0; N <= n; N++)
        {
            int nottake = 0 + dp[ind - 1][N];
            int rodlength = ind + 1;
            if (rodlength <= N)
                take = price[ind] + dp[ind][N - rodlength];

            dp[ind][N] = max(take, nottake);
        }
    }

    return dp[n - 1][n];
}