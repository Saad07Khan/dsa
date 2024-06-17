class Solution
{
public:
    bool possible(vector<int> &bloomDay, int m, int k, int mid)
    {
        int count = 0;
        int adjacent = 0;

        for (int i = 0; i < bloomDay.size(); i++)
        {
            if (bloomDay[i] <= mid)
            {
                count++;
            }
            else
            {
                adjacent += (count / k);
                count = 0;
            }
        }
        adjacent += (count / k);

        if (adjacent >= m)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int n = bloomDay.size();
        long long pdt = (long long)m * k; //edge case
        if (pdt > n)
            return -1;
        int low = INT_MAX, high = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            low = min(bloomDay[i], low);
            high = max(bloomDay[i], high);
        }
        while (low <= high)
        {

            int mid = (low + high) / 2;

            if (possible(bloomDay, m, k, mid) == 1)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return low;
    }
};