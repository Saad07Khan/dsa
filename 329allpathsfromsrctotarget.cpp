class Solution {
public:

    void dfs(int node,int target,vector<vector<int>>&graph,vector<int>&path,vector<vector<int>>&ans)
    {
        path.push_back(node);
        if(node==target)
        {
            ans.push_back(path);
            return;
        }

        for(auto it: graph[node])
        {
            dfs(it,target,graph,path,ans);
            path.pop_back();
        }
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        int target=n-1;
        vector<vector<int>>ans;
        vector<int>path;
        dfs(0,target,graph,path,ans);
        return ans;
    }
};