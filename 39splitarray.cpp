class Solution {
public:

int summation(vector<int>& nums)
{
    int sum=0;
    for(int i=0;i<nums.size();i++)
    {
        sum+=nums[i];
    }
    return sum;
}

int check(vector<int>& nums, int mid)
{
    int count=1;
    int sum=0;

    for(int i=0;i<nums.size();i++)
    {
        if(sum+nums[i]>mid)
        {
            count+=1;
            sum=nums[i];
        }
        else
        {
            sum+=nums[i];
        }

    }
    return count;
}


    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());
        int high = summation(nums);

        while(low<=high)
        {
            int mid=(low+high)/2;

            int checker= check(nums,mid);

            if(checker<=k)
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