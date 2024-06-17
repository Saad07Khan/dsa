
//memoization
class Solution {
public:

//starting from begining instead of reverse in this problem
    int f(int i, int j, vector<vector<int>>& triangle,vector<vector<int>>& dp, int rowsize)
    {
        if(i==rowsize-1)
        {
            return triangle[rowsize-1][j];
        }

        if(dp[i][j]!=-1)return dp[i][j];

        int down = triangle[i][j]+ f(i+1,j,triangle,dp,rowsize);
        int diag = triangle[i][j]+ f(i+1,j+1,triangle,dp,rowsize);

        return dp[i][j] = min(down,diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        return f(0,0,triangle,dp,m);

    }
};

//tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,-1));
        
        for(int j=0;j<m;j++)dp[m-1][j]=triangle[m-1][j]; //base case from recursive soln

        for(int i=m-2;i>=0;i--) //starting from m-2 as m-1 ie last row already covered up
        {
            for(int j=i;j>=0;j--) // since triangle, start j from i onwards
            {
                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down,diag);
            }
        }
        return dp[0][0]; // since in memoization we start with 0,0 
    }
};