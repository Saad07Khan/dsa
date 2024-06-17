class DisjointSet
{
public:
    vector<int> rank, parent, size;
    // rank: array to store rank of each set
    // parent: array to store parent of each node
    // size: array to store size of each set
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        // initialize each node as a parent of itself
        // and the size of each set as 1
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node)
    {
        // find the ultimate parent of the given node
        // using path compression
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        // union two sets based on their rank
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        // union two sets based on their size
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    bool isValid(int newrow,int newc, int n)
    {
        if(newrow>=0 && newrow<n && newc>=0 && newc<n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);

        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]==0)continue;
                int rj[] = {-1, 0, +1, 0};
                int cj[] = {0, 1, 0, -1};
                for(int i=0;i<4;i++)
                {
                    int newr= row+rj[i];
                    int newcol=col+cj[i];
                    if(isValid(newr,newcol,n)&&grid[newr][newcol]==1)
                    {
                        int nodeNo= row*n+col;
                        int adjnodeNo= newr *n+newcol;
                        ds.unionBySize(nodeNo,adjnodeNo);
                    }
                }
            }
        }
        int maxi=0;
        //part 2
        for(int row=0;row<n;row++)
        {
            for(int col=0;col<n;col++)
            {
                if(grid[row][col]==1)continue;
                int rj[] = {-1, 0, +1, 0};
                int cj[] = {0, 1, 0, -1};
                set<int>components;
                for(int i=0;i<4;i++)
                {
                    int newr=row+rj[i];
                    int newcol=col+cj[i];
                    if(isValid(newr,newcol,n)&&grid[newr][newcol]==1)
                    {
                        components.insert(ds.findUPar(newr*n+newcol));
                    }

                }
                int sizetotal=1;
                for(auto it:components)
                {
                    sizetotal+=ds.size[it];
                }
                maxi=max(maxi,sizetotal);
            }
        }
        for(int cellno=0;cellno<n*n;cellno++)
        {
            maxi=max(maxi,ds.size[ds.findUPar(cellno)]);

        }
        return maxi;
        
    }
};