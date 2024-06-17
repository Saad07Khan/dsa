class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<int> adj[], int vis[],vector<int>&ans)
    {
        vis[node]=1;
        ans.push_back(node);
        for(auto it: adj[node])
        {
            if(vis[it]!=1)
            {
                dfs(it,adj,vis,ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
       int vis[V]={0};
       int start=0;
       vector<int>ans;
       dfs(start,adj,vis,ans);
       return ans;
       
    }
};