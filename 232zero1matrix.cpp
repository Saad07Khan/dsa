class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>distance(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==0)
                {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }

        int row[] = {-1, 0, +1, 0};
        int col[] = {0, 1, 0, -1};

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c= q.front().first.second;
            int d= q.front().second;
            q.pop();
            distance[r][c]=d;
            for(int i=0;i<4;i++)
            {
                int ij= r+row[i];
                int cj= c+col[i];
                if(ij>=0&&ij<n&&cj>=0&&cj<m&&vis[ij][cj]==0)
                {
                    vis[ij][cj]=1;
                    q.push({{ij,cj},d+1});
                }
            }
        }

        return distance;
    }
};