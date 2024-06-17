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

   int total(vector<int>& weights)
   {
       int sum=0;

       for(int i=0;i<weights.size();i++)
       {
           sum+=weights[i];
       }
       return sum;
   }


int findDays(vector<int> &weights, int cap) {
    int days = 1;   // Initialize the number of days to 1 (the first day).
    int load = 0;   // Initialize the current load carried to 0.
    int n = weights.size(); // Get the total number of weights in the vector.
    
    for (int i = 0; i < n; i++) {
        if (load + weights[i] > cap) {
            days += 1; // If adding the weight exceeds the capacity, move to the next day.
            load = weights[i]; // Set the load for the next day to the current weight.
        }
        else {
            // If adding the weight does not exceed the capacity, load it on the same day.
            load += weights[i];
        }
    }
    return days; // Return the total number of days required to transport all weights.
}


    int shipWithinDays(vector<int>& weights, int days) {

        int low= getmax(weights);
        int high= total(weights);
        
        while(low<=high)
        {
            int mid=(low+high)/2;

            int day=findDays(weights, mid);

            if(day<=days)
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


