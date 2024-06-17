class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {


        map<int,int>mpp;

        for(int i=0;i<nums.size();i++)
        {
            int num= nums[i];
            int more = target-num;

            if(mpp.find(more)!=mpp.end()) // means more is present in hashmap
            {
                return{mpp[more],i}; // use curly brackets when ret more than 1 index
            }

            mpp[nums[i]]=i; //stores the element and its indice in hashmap
        }
        return {};

   
        
        // brute force approach
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {}; // No solution found
    }
};