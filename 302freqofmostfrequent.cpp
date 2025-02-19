class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
     int n=nums.size();
     sort(nums.begin(),nums.end());
     long long i=0, sum=0,ans=1;
     for(int j=0;j<n;j++)
     {
        sum+=nums[j];
        while((j-i+1)*nums[j]-sum>k)
        {
            sum-=nums[i];//shrink the window
            i++;

        }

        ans=max(ans,j-i+1);
     }

     return ans;
    }
};