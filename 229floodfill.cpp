//using bfs
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int row[] = {-1, 0, +1, 0};
        int col[] = {0, 1, 0, -1};

        int pixel = image[sr][sc];
        while (!q.empty())
        {
            int r = q.front().first;
            int c = q.front().second;
            image[r][c] = color;
            vis[r][c] = 1;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int ij = r + row[i];
                int cj = c + col[i];
                if (ij >= 0 && ij < n && cj >= 0 && cj < m && image[ij][cj] == pixel && vis[ij][cj] == 0)
                {
                    q.push({ij, cj});
                    image[ij][cj] = color;
                    vis[ij][cj] = 1;
                }
            }
        }

        return image;
    }
};