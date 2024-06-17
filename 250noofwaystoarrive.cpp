class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> adj[n];
        for (auto it : roads) {
            adj[it[0]].push_back({ it[1], it[2] });
            adj[it[1]].push_back({ it[0], it[2] });
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({ 0, 0 });
        vector<long long> dista(n, 1e18);
        dista[0] = 0;
        vector<long long> findways(n, 0);
        findways[0] = 1;

        int mod = (int)(1e9 + 7);
        while (!pq.empty()) {
            long long int dist = pq.top().first;
            long long int node = pq.top().second;
            pq.pop();
            for (auto it : adj[node]) {
                long long int adjnode = it.first;
                long long int adjdist = it.second;

                if (dist + adjdist < dista[adjnode]) {
                    dista[adjnode] = dist + adjdist;
                    pq.push({ dist + adjdist, adjnode });
                    findways[adjnode] = findways[node];
                } else if (dist + adjdist == dista[adjnode]) {
                    findways[adjnode] = (findways[adjnode] + findways[node]) % mod;
                }
            }
        }
        return findways[n - 1] % mod;
    }
};
