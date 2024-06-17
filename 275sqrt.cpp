class Solution {
public:
    bool judgeSquareSum(int c) {
        long long high= sqrt(c);

        long long low=0;

        while(low<=high)
        {
            long long ans = (low*low)+(high*high);
            if(ans<c)
            {
                low++;
            }
            else if(ans>c)
            {
                high--;
            }

            else if(ans==c)
            {
                return true;
            }
        }
        return false;


    }
};