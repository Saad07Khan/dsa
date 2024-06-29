class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int>indegree(n,0);
        for(auto it: roads)
        {
            int u= it[0];
            int v=it[1];
            indegree[u]++;
            indegree[v]++;
        }

        sort(indegree.begin(),indegree.end());
        
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+= (long long )indegree[i]*(i+1);

        }
        return sum;
    }
};