class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        double mini=INT_MAX;
        while(i<j)
        {
            int smallest= nums[i];
            int largest = nums[j];
            double average = ((double)smallest+(double)largest)/2;
            mini=min(mini,average);
            i++;
            j--;
        }

        return mini;
        
    }
};