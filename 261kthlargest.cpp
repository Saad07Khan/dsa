class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //first k-1 elements, create a max heap
        //k to n-1 elements, if element< heap.top(), heap.pop(), heap.push(element)
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
        }
        for(int i=k;i<nums.size();i++)
        {
            if(nums[i]>pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        int ans=pq.top();
        return ans;
    }
};
