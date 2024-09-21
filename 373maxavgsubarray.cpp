class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        // double ans;
        int i=0;
        double maxi=INT_MIN;
        for(int j=0;j<n;j++)
        {
            sum+=nums[j];

            while(j-i+1>k)
            {
               
                sum-=nums[i];
                 i++;
            }

            if(j-i+1==k)
            {
                double ans= double(sum)/(k);
                maxi=max(maxi,ans);
            }
        }

        return (double)maxi;
    }
};