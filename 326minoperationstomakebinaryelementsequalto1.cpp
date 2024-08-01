class Solution {
public:
    int minOperations(vector<int>& nums) {

        int n=nums.size();
        int operation =0;
        for(int j=0;j<n-2;j++)
        {
           if(nums[j]==0)
           {
            int i=j;
            while(i<j+3)
            {
                if(nums[i]==0)
                {
                    nums[i]=1;
                }
                else
                {
                    nums[i]=0;
                }

                
                i++;
            }
            operation++;
           }
        }


        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                return -1;
            }
        }

        return operation;
        
    }
};