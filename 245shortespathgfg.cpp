class Solution
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[source.first][source.second] = 0;
        queue<pair<pair<int, int>, int>> q;
        q.push({{source.first, source.second}, 0});
        if (source.first == destination.first && source.second == destination.second)
            return 0;
        int row[] = {-1, 0, +1, 0};
        int col[] = {0, 1, 0, -1};

        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ij = r + row[i];
                int cj = c + col[i];
                if (ij >= 0 && ij < n && cj >= 0 && cj < m && 1 + dis < dist[ij][cj] && grid[ij][cj] == 1)
                {
                    dist[ij][cj] = 1 + dis;
                    if (ij == destination.first && cj == destination.second)
                    {
                        return 1 + dis;
                    }
                    q.push({{ij, cj}, 1 + dis});
                }
            }
        }
        return -1;
    }
};