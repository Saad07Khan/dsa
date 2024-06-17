class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n=nums.size();
        vector<int>lp(n,1); // initially all elements of the arrays are initialized to 1 to make it easier to multiply
        vector<int>rp(n,1);
        vector<int>ans(n,1);

        lp[0]=1;
        rp[n-1]=1;

        for(int i=1;i<n;i++)
        {
            lp[i]=nums[i-1]*lp[i-1];
        }
        for(int i=n-2;i>=0;i--)            // to multiply with the last element of the array
                                           // i>=0 as we need to go until the ith index
        {
            rp[i]=nums[i+1]*rp[i+1];
        }
        for(int i=0;i<n;i++)
        {
            ans[i]=lp[i]*rp[i];
        }
        return ans;
    }
};