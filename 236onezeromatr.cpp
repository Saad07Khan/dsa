class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    queue<pair<pair<int,int>,int>>q;
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                vis[i][j]=1;
	                q.push({{i,j},0});
	            }
	        }
	    }
	    
	    int row[] = {-1, 0, +1, 0};
        int col[] = {0, 1, 0, -1};
	    while(!q.empty())
	    {
	        int r=q.front().first.first;
	        int c=q.front().first.second;
	        int d=q.front().second;
	        q.pop();
	        ans[r][c]=d;
	        for(int i=0;i<4;i++)
	        {
	            int ij=r+row[i];
	            int cj=c+col[i];
	            if(ij>=0&&ij<n&&cj>=0&&cj<m&&grid[ij][cj]==0&&vis[ij][cj]!=1)
	            {
	                vis[ij][cj]=1;
	                q.push({{ij,cj},d+1});
	                
	            }
	        }
	    }
	    return ans;
	}
};