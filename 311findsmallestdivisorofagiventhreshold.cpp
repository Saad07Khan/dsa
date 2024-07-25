class Solution {
public:

  int maximum(vector<int>&nums)
    {
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            maxi=max(maxi,nums[i]);
        }

        return maxi;
    }
    bool isPossible(vector<int>&nums,int mid, int threshold)
    {
        long long sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=ceil((double)nums[i]/(double)mid);
        }

        if(sum<=threshold)
        {
            return true;
        }

        else
        {
             return false;
        }
       
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int low=1;
        int high= maximum(nums);
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(isPossible(nums,mid,threshold)==true)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;

    }
};