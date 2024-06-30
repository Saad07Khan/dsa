class Solution
{
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(n);
        vector<set<int>> ans(n);
        vector<vector<int>> res(n);
        vector<int> ind(n, 0);
        for (int i = 0; i < edges.size(); i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            ind[edges[i][1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (ind[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            for (auto it : adj[x])
            {
                ind[it]--;
                ans[it].insert(x);
                if (ind[it] == 0)
                {
                    q.push(it);
                }

                for (auto j : ans[x])
                {
                    ans[it].insert(j);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (auto j : ans[i])
            {
                res[i].push_back(j);
            }
        }

        return res;
    }
};