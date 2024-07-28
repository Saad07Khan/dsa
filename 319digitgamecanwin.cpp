class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n=nums.size();
        int singlesum=0;
        int doublesum=0;


        for(int i=0;i<n;i++)
        {
            if(nums[i]>=1&& nums[i]<=9)
            {
                singlesum+=nums[i];
            }

            if(nums[i]>=10 &&nums[i]<=99)
            {
                doublesum+=nums[i];
            }
        }
        return singlesum>doublesum || doublesum>singlesum;
    }
};