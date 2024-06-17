class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V);
        for (int i = 0; i < V; i++)
        {
            dist[i] = 1e9; // initializing initially with infinity
        }

        dist[S] = 0;
        pq.push({0, S});
        while (!pq.empty())
        {
            int current_dist = pq.top().first; // Use a different name here
            int node = pq.top().second;
            pq.pop();

            for (auto it : adj[node])
            {
                int edgeWeight = it[1];
                int adjNode = it[0];

                if (current_dist + edgeWeight < dist[adjNode])
                {
                    dist[adjNode] = current_dist + edgeWeight; // Use the new name here
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
