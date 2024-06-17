
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSafe(int node, int col, int color[], int n, bool graph[101][101])
    {
        for (int k = 0; k < n; k++)
        { // means its not the same node itself,///there exists an adjacent node,//the color already exists on the node
            if (k != node && graph[node][k] == 1 && color[k] == col)
            {
                return false;
            }
        }
        return true;
    }

    bool solve(int node, int color[], int n, int m, bool graph[101][101])
    {
        if (node == n)
        {
            return true;
        }

        for (int col = 1; col <= m; col++)
        {
            if (isSafe(node, col, color, n, graph))
            {
                color[node] = col;
                if (solve(node + 1, color, n, m, graph) == true)
                {
                    return true;
                }

                color[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        int color[n] = {0};
        if (solve(0, color, n, m, graph) == true)
            return true;
        return false;
    }
};






int index = if leftoright? i: size-i-1;
