class DisjointSet {
public: 
    vector<int> rank, parent, size; 
    // rank: array to store rank of each set
    // parent: array to store parent of each node
    // size: array to store size of each set
    DisjointSet(int n) {
        rank.resize(n+1, 0); 
        parent.resize(n+1);
        size.resize(n+1); 
        // initialize each node as a parent of itself
        // and the size of each set as 1
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
        }
    }
    int findUPar(int node) {
        // find the ultimate parent of the given node
        // using path compression
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionByRank(int u, int v) {
        // union two sets based on their rank
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v; 
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u; 
        }
        else {
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        // union two sets based on their size
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cntextras=0;
        for(auto it: connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findUPar(u)==ds.findUPar(v))
            {
                cntextras++;
            }
            else
            {
                ds.unionBySize(u,v);
            }
        }
        int cnC=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)cnC++;
        }
        int ans=cnC-1;
        if(cntextras>=ans)
        {
            return ans; // if we have enough extra cables to connect all the components, return the answer
        }
        return -1;


    
    }
};