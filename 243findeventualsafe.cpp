
// Terminal nodes, initially with outdegree 0, transform into nodes with indegree 0 after reversal. Using Kahn's algorithm identifies nodes with linear dependencies on these terminals or in the path to them. Nodes in cycles or pointing to cycles cannot reach terminals due to cyclic dependencies along the path.
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        // vector<vector<int>>adjrev(n);
        vector<int> adjrev[n];
        vector<int>indegree(n,0);

        for(int i=0;i<n;i++)
        {
            for(auto it: graph[i])
            {
                //nodes from:
                //i->it (before)
                //it->i (now)
                adjrev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int node= q.front();
            q.pop();
            ans.push_back(node);
            for(auto it: adjrev[node])
            {
                indegree[it]--;
                if(indegree[it]==0)
                {
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;


    }
};