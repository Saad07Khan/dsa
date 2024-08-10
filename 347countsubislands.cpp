class Solution {
public:

    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int n, int m)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid2[i][j]!=1)
        {
            return true;
        }

        if(grid1[i][j]==0)
        {
            return false;
        }

        grid2[i][j]=2;

        bool a=dfs(grid1,grid2,i-1,j,n,m);
        bool b=dfs(grid1,grid2,i,j-1,n,m);
        bool c=dfs(grid1,grid2,i+1,j,n,m);
        bool d=dfs(grid1,grid2,i,j+1,n,m);

        return a&&n&&c&&d;

    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        int ans=0; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid2[i][j]==1)
                {
                    if(dfs(grid1,grid2,i,j,n,m))
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
      
    }
};