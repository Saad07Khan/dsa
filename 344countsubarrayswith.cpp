class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,nums[i]);
        }
        int start=0;

        long long count=0;

        for(int end=0;end<n;end++)
        {
            if(nums[end]==maxi)k--;
            while(!k)
            {
                if(nums[start]==maxi)
                {
                    k++;
                }
                start++;
            }
            count+=start;
        }
        return count;
  
        
    }
};