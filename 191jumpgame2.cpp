class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int current=0;
        int farthest=0;
        int n=nums.size();
        for(int i=0;i<n-1;i++) //until n-1 so extra jump not counted
        {
            farthest=max(farthest,nums[i]+i);
            if(i==current)
            {
                current=farthest;
                jumps++;    
            }
        }


        return jumps;
    }
};