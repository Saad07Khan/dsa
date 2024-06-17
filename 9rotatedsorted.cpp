/* first check if right or left half is sorted or not
if either of half is sorted, check if the target is available in that half if yes eliminated unsorted half if
if no eliminate itself
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low=0, n=nums.size();
        int high = n-1;
        

        while(low<=high)
        {
            int mid = (low+high)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            if(nums[low]<=nums[mid])
            {
                if(nums[low]<= target && target<= nums[mid])
                {
                    high = mid-1;
                }
                else{
                    low = mid+1;
                }
            }

            else
            {
                if(nums[mid]<=target && target<=nums[high] )
                {
                    low=mid+1;
                }
                else
                {
                    high=mid-1;
                }
            }
        }
        return -1;

        

        
    }
};