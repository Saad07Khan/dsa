class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        map<int,int> m; int presum = 0, count = 0; 
         m[0] = 1; //m[0] = 1;: This line initializes the map with an initial entry of (0, 1). This is done to account for subarrays that start at the beginning of the array and have a sum of k.
         // map stores the prefix sum and the frequency of that prefix sum
        for(int i=0; i<nums.size(); i++){
            presum += nums[i]; 
            if(m.find(presum-k) != m.end()) 
            count += m[presum-k];

            m[presum]++; 
        }
        return count; 

    }
};
