class Solution {
  public:
    // Function to detect cycle in an undirected graph
    
    bool detect(int node, vector<int>adj[], int vis[])
    {
        vis[node]=1;
        queue<pair<int,int>>q;
        q.push({node,-1});
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjacent: adj[node])
            {
                if(!vis[node])
                {
                    vis[node]=1;
                    q.push({adjacent,node});
                }
                else if(parent!=adjacent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        int vis[V]={0};
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(detect(i,adj,vis)==true) return true;
            }
        }
        
        return false;
    }
};