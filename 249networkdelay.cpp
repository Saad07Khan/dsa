class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto it: times)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dista(n+1,INT_MAX);
        dista[k]=0;
        pq.push({0,k});

        while(!pq.empty())
        {
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto it: adj[node])
            {
                int adjdist=it.second;
                int adjnode=it.first;
                if(dist+adjdist<dista[adjnode])
                {
                    dista[adjnode]=dist+adjdist;
                    pq.push({dist+adjdist,adjnode});
                }
            
            }
        }

        int maxi=0;
        for(int i=1;i<=n;i++)
        {
            maxi=max(maxi,dista[i]);
        }
        if(maxi==INT_MAX)
        {
            return -1;
        }
        else
        {
            return maxi;
        }

    }
};