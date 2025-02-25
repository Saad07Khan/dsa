class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n= nums.size();
        priority_queue<long long int, vector<long long int>, greater<long long int>>pq;
       
        for(auto it: nums)
        {
            pq.push(it);
        }

        int count=0;
        while(pq.top()<k)
        {
            long long int  x=pq.top();
            pq.pop();
            long long int y=pq.top();
            pq.pop();
            long long int ans= (min(x, y) * 2 + max(x, y));
            pq.push(ans);
            count++;


        }

        return count;
    }
};