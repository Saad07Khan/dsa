class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        int sum=0;
        int count=0;
        int i=0;
        for(int j=0;j<n;j++)
        {
            sum+=arr[j];
            while(j-i+1==k)
            {
                if(sum/k>=threshold)
                {
                count++;
                }
                 sum-=arr[i];
                i++;
            }

        }
        return count;
    }
};