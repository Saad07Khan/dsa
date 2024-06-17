class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        int rsum= 0;
        for (int i=0; i<nums.size(); i++){
            rsum+= nums[i];
            ans.push_back(rsum);
        }
        return ans;
        
    }
};