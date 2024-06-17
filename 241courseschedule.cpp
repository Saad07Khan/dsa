class Solution {
public:
    bool canFinish(int numcourses, vector<vector<int>>& prerequisites) {
        int n = numcourses;  // Updated variable name

        vector<int> adj[n];
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]); //to take course 0 you have to take course 1(opposite)
        }

        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return count == n;
    }
};
