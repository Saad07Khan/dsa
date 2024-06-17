class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int, pair<int, int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});

        int row[] = {-1, 0, +1, 0};
        int col[] = {0, 1, 0, -1};
        while(!pq.empty())
        {
            int diff=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            if(r==n-1&&c==m-1)return diff; //as it is priority queue 
            for(int i=0;i<4;i++)
            {
                int ij=r+row[i];
                int cj=c+col[i];
                if(ij>=0&&ij<n&&cj>=0&&cj<m)
                {
                    int newEffort= max(abs(heights[r][c]-heights[ij][cj]),diff);
                    if(newEffort<dist[ij][cj])
                    {
                        dist[ij][cj]=newEffort;
                        pq.push({newEffort,{ij,cj}});
                    }
                }
            }
        }
        return 0;
    }
};