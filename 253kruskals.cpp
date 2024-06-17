class DisjointSet{
    vector<int>rank,parent,size;
}
public:
DisjointSet(int n)
{
    size.resize(n+1,1);//if 1 based indexing, n+1 works for both 0 based and 1 based
    parent.resize(n+1);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
}

int findUpar(int node)
{
    if(parent[node]==node)
    {
        return node;
    }
    else
    return parent[node]=findUpar(parent[node]);
}

void unionbysize(int u, int v)
{
    int ulp_u=findUpar(u);
    int ulp_v=findUpar(v);
    if(size[ulp_u]<size[ulp_v])
    {
        parent[ulp_u]=parent[ulp_v];
        size[ulp_v]+=size[ulp_u];
    }
    else
    {
        parent[ulp_v]=parent[ulp_u];
        size[ulp_u]+=size[ulp_v];
    }
}
class Solution
{
    
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++)
        {
            for(auto it: adj[i])
            {
                int adjNode=it[0];
                int wt=it[1];
                int node=i;
                edges.push_back({wt,{node,adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mstSum=0;
        for(auto it: edges)
        {
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.findpar(nd)!=ds.findpar(adjnd))
            {
                mstSum+=wt;
                ds.unionbysize(u,v);
            }
        }
        return mstsum;
    }
};