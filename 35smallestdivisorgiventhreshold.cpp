class Solution {
public:


int getmax(vector<int>& nums)
{
    int mx=INT_MIN;

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i]>mx)
        {
            mx=nums[i];
        }
    }
    return mx;
}

int getdiv(vector<int>& nums, int mid)
{
    long long sum=0;

    for(int i=0;i<nums.size();i++)
    {
        sum+= ceil(double(nums[i])/(double)mid);
    }

    return sum;
}
    int smallestDivisor(vector<int>& nums, int threshold) {


        int low=1;
        int high= getmax(nums);

        while(low<=high)
        {
            int mid=(low+high)/2;

            long long checker = getdiv(nums,mid);

            if(checker<=threshold)
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