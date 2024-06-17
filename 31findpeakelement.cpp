//Brute force solution

class Solution {
public:
    int findPeakElement(vector<int>& nums) {             //time complexity is O(n)

        int max=nums[0];
        int n= nums.size();
        // int ind;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>max)
            {
                max=nums[i];
            }
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]==max)
            {
                return i;
            }
        }
        return -1; // dummy return statement when you return something inside a for   loop this is required and since function return type is int

        // return ind;
        
    }
};