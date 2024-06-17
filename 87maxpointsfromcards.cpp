class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        vector<int> presum(n, 0);

        int score = 0;
        int sum = 0;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            sum += cardPoints[i];
            presum[i] = sum;
        }

        if (n == k)
        {
            return sum; // Return the sum of all elements in this case.
        }

        for (int i = 0; i <= k; i++)
        {
            int j = i + n - k - 1;
            if (i == 0)
            {
                ans = presum[j];
            }
            else
            {
                ans = presum[j] - presum[i - 1];
            }

            score = max(score, sum - ans);
        }
        return score;
    }
};
