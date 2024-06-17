class Solution
{
public:
    // approach 1:
    double signFunc(double product)
    {
        if (product > 0)
        {
            return 1;
        }
        else if (product < 0)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
    int arraySign(vector<int> &nums)
    {

        double prod = 1;

        for (int i = 0; i < nums.size(); i++)
        {

            prod *= nums[i];
        }

        return signFunc(prod);
    }
};

// approach 2, if negcount is odd means final ans is negative
//  if negcount is even means final ans is positive
class Solution
{
public:
    int arraySign(vector<int> &nums)
    {

        int negcount = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            if (nums[i] == 0)

                return 0; // not using brackets in if statements decrease runtime

            if (nums[i] < 0)

                negcount++;
        }

        if (negcount % 2 == 0)

            return 1;

        else

            return -1;
    }
};