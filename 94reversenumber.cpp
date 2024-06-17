class Solution
{
public:
    int reverse(int x)
    {

        int revn = 0;
        int lastdigit;

        while (x != 0)
        {
            lastdigit = x % 10;

            if ((revn > INT_MAX / 10) || (revn < INT_MIN / 10))
            {
                return 0;
            }
            revn = (revn * 10) + lastdigit;
            x = x / 10;
        }
        return revn;
    }
};
