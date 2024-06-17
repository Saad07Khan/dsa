class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<int>vis(V,0);
        pq.push({0,0}); //dist and node, not parent as mst is not asked only sum
        int sum=0;
        while(!pq.empty())
        {
            
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(vis[node]==1)continue;
            vis[node]=1;
            sum+=dist;
            
            for(auto it: adj[node])
            {
                int adjnode=it[0];
                int edgeweight=it[1];
                if(vis[adjnode]!=1)
                {
                    pq.push({edgeweight,adjnode});
                }
            }
        }
        return sum;
    }
};