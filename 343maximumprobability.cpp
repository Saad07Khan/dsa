class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>>adjList(n);
        for(int i=0;i<edges.size();i++)
        {
            adjList[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0],succProb[i]});

        }
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});
        vector<double>dist(n,0.0);

        while(!pq.empty())
        {
            auto t=pq.top();
            pq.pop();
            double currProb=t.first;
            int currNode=t.second;
            if(currProb<dist[currNode])continue;
            for(auto adjNode: adjList[currNode])
            {
                if(currProb*adjNode.second>dist[adjNode.first])
                {
                    pq.push({currProb*adjNode.second,adjNode.first});
                    dist[adjNode.first]=currProb*adjNode.second;
                }
            }
        }
        return dist[end_node];
    }
};