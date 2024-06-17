#include <bits/stdc++.h>




class DisjointSet{
    vector<int>rank,parent,size;
}
public:
DisjointSet(int n)
{
    size.resize(n+1,1);//if 1 based indexing, n+1 works for both 0 based and 1 based
    parent.resize(n+1);
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
    }
}

int findUpar(int node)
{
    if(parent[node]==node)
    {
        return node;
    }
    else
    return parent[node]=findUpar(parent[node]);
}

void unionbysize(int u, int v)
{
    int ulp_u=findUpar(u);
    int ulp_v=findUpar(v);
    if(size[ulp_u]<size[ulp_v])
    {
        parent[ulp_u]=parent[ulp_v];
        size[ulp_v]+=size[ulp_u];
    }
    else
    {
        parent[ulp_v]=parent[ulp_u];
        size[ulp_u]+=size[ulp_v];
    }
}
int main()
{
     DisjointSet ds(7);
    ds.unionBySize(1, 2); 
    ds.unionBySize(2, 3); 
    ds.unionBySize(4, 5); 
    ds.unionBySize(6, 7); 
    ds.unionBySize(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionBySize(3, 7); 

    if(ds.findUPar(3) == ds.findUPar(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 
	return 0;


}