class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
         if(grid[0][0]==1)
        {
            return -1;
        }
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int, int>, int>> q;
        q.push({{0,0},1});
        int row[] = {0,0,1,1,1,-1,-1,-1};
        int col[] = {1,-1,0,1,-1,0,1,-1};

        while(!q.empty())
        {
            int r=q.front().first.first;
            int c=q.front().first.second;
            int dis=q.front().second;
            // if(r==n-1&&c==m-1)
            // {
            //     return dis;
            // }
            q.pop();
            
            for(int i=0;i<8;i++)
            {
                int ij=r+row[i];
                int cj=c+col[i];
                if(ij>=0&&ij<n&&cj>=0&&cj<m&& vis[ij][cj]!=1&&grid[ij][cj]==0)
                {
                    vis[ij][cj]=1;
                    if(ij==n-1&&cj==m-1)
                    {
                        return dis+1;
                    }
                    q.push({{ij,cj},dis+1});
                }
            }

        }
        return -1;

    }
};