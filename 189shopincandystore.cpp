class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        int buy=0;
        int free=N-1;
        int mini=0;     
        while(buy<=free)
        {
            mini=mini+candies[buy];
            buy++;
            free=free-K;
        }   
        int maxi=0;
        buy=N-1;
        free=0;
        while(buy>=free)
        {
            maxi=maxi+candies[buy];
            buy--;
            free=free+K;
        }   
        vector<int>ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
};