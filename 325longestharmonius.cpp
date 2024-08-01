class Solution {
public:

    int atMost(vector<int>&nums)
    {
        int n=nums.size();
        int i=0;
        int ans=0;
        sort(nums.begin(),nums.end());
        for(int j=0;j<n;j++)
        {
           if(nums[j]-nums[i]==1)
           {
            ans=max(ans,j-i+1);
           }
            while(i<=j && nums[j]-nums[i]>1)
            {
              i++;
            }
        }

        return ans;
    }
    int findLHS(vector<int>& nums) {

        return atMost(nums);
     
    }
};