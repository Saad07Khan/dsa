class Solution {
public:
     int maxProduct(vector<int>& nums) {
        int pre=1;
        int suff=1;
        int n=nums.size();
        int maxprod=INT_MIN;
        for(int i=0;i<n;i++){
            if(pre==0) pre=1;
            if(suff==0) suff=1;
            pre*=nums[i];
            suff*=nums[n-i-1];
            maxprod=max(maxprod,(max(pre,suff))); 
        }
        return maxprod;
    }
};