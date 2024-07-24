class Solution {
public:
    int minOperations(vector<int>& nums) {
        int j=0;
        int n=nums.size();
        int ans=n;
        sort(begin(nums),end(nums));
        nums.erase(unique(begin(nums),end(nums)),end(nums));
        int m=nums.size();
        

        for(int i=0;i<m;i++)
        {
            while(j<m && nums[j]<nums[i]+n)
            {
                j++;
            }

            ans=min(ans,n-j+i);
        }
        return ans;
        
    }
};

