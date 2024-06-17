class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {

        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        vis[0][0]=0;
        pq.push({grid[0][0],{0,0}});//t,i,j
        int row[] = {-1, 0, +1, 0};
        int col[] = {0, 1, 0, -1};
        while(!pq.empty())
        {
            int t=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();
            if(r==n-1&&c==m-1)return t;
            for(int i=0;i<4;i++)
            {
                int ij=r+row[i];
                int cj=c+col[i];
                if(ij>=0&&ij<n&&cj>=0&&cj<m &&vis[ij][cj]==0)
                {
                    vis[ij][cj]=1;
                    pq.push({max(t,grid[ij][cj]),{ij,cj}});
                }
            }
        }
        return -1;

    }
};