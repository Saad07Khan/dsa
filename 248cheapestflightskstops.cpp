class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<int,pair<int,int>>>q;
        vector<pair<int,int>>adjLs[n];
        vector<int>dis(n,1e9);
        dis[src]=0;
        for(auto it:flights)
        {
            // node                //adj  //edgeweight

            adjLs[it[0]].push_back({it[1],it[2]});
        }
        q.push({0,{src,0}});

        while(!q.empty())
        {
            auto it1=q.front();
            q.pop();
            int stops=it1.first;
            int node=it1.second.first;
            int cost=it1.second.second;
            if(stops>k)continue;
            for(auto it2:adjLs[node])
            {
                int adjNode= it2.first;
                int edgeWeight= it2.second;
                if(cost+edgeWeight<dis[adjNode]&&stops<=k)
                {
                    dis[adjNode]=cost+edgeWeight;
                    q.push({stops+1,{adjNode,cost+edgeWeight}});
                }
            }
        }
        if(dis[dst]==1e9)return {-1};
        return dis[dst];
    }
};