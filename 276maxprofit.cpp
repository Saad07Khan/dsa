#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        vector<pair<int, int>> difprof(n);
        for(int i = 0; i < n; i++) {
            difprof[i] = {difficulty[i], profit[i]};
        }

        int w = worker.size();
        priority_queue<int> pq;
        int prof = 0;

        for(int i = 0; i < w; i++) {
            for(int j = 0; j < n; j++) {
                if(worker[i] >= difprof[j].first) {
                    pq.push(difprof[j].second);
                }
            }
            if(!pq.empty()) {
                prof += pq.top();
                pq.pop();
            }

            cout << prof << " ";
        }
        return prof;
    }
};

int main() {
    vector<int> difficulty = {2, 4, 6, 8, 10};
    vector<int> profit = {10, 20, 30, 40, 50};
    vector<int> worker = {4, 5, 6, 7};

    Solution sol;
    int result = sol.maxProfitAssignment(difficulty, profit, worker);
    cout << "Total profit: " << result << endl;

    return 0;
}


class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

        int n=difficulty.size();
        vector<pair<int,int>>difprof;
        for(int i=0;i<n;i++)
        {
            difprof.push_back({difficulty[i],profit[i]});
        }

        sort(worker.begin(),worker.end());
        sort(difprof.begin(),difprof.end());
        int w=worker.size();

        int prof=0;
        int maxi=0;

        int j=0;
        for(int i=0;i<w;i++)
        {

        while(j<n && worker[i]>=difprof[j].first)
        {
            maxi=max(maxi,difprof[j].second);
            j++;
        }

        prof+=maxi;

        }
        return prof;


        
    }
};