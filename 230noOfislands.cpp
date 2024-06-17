//using bfs
class Solution {
public:

    void bfs(int i, int j, vector<vector<char>>&grid,vector<vector<int>>&vis,int row[], int col[],int n, int m)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
         while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++)
            {
                int rown=r + row[i];
                int coln= c+col[i];
                if(rown>=0 && rown<n && coln>=0 && coln<m && vis[rown][coln]!=1 && grid[rown][coln]=='1'){
                    q.push({rown,coln});
                    vis[rown][coln]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
    
        int row[] = {-1, 0, +1, 0};
        int col[] = {0, 1, 0, -1};
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]!=1)
                {
                    count++;
                    bfs(i,j,grid,vis,row,col,n,m);
                }
            }
        }
        return count;
        
    }
};

//using dfs
class Solution {
public:

void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis, int row[], int col[], int n, int m)
{
    vis[i][j] = 1;

    for (int k = 0; k < 4; k++)
    {
        int rown = i + row[k];
        int coln = j + col[k];
        if (rown >= 0 && rown < n && coln >= 0 && coln < m && vis[rown][coln] != 1 && grid[rown][coln] == '1')
        {
            dfs(rown, coln, grid, vis, row, col, n, m);
        }
    }
}

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
    
        int row[] = {-1, 0, +1, 0};
        int col[] = {0, 1, 0, -1};
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && vis[i][j]!=1)
                {
                    count++;
                    dfs(i,j,grid,vis,row,col,n,m);
                }
            }
        }
        return count;
        
    }
};