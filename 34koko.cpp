class Solution {
public:

         long long calculatehours(vector<int>& piles, int mid)
        {
            long long total=0;

            for(int i=0;i<piles.size();i++)
            {
                total+= ceil((double)piles[i]/(double)mid);
            }

            return total;
        }



        int getMax(vector<int> piles)
        {
            int max= INT_MIN;

            for(int i=0;i<piles.size();i++)
            {
                if(piles[i]>max)
                {
                    max=piles[i];
                }
            }

            return max;
        }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high= getMax(piles);

        while(low<=high)
        {
            int mid= (low+high)/2;

            long long check = calculatehours(piles,mid);

            if(check<=h)
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