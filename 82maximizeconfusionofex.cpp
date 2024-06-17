class Solution
{
public:
    int truecount(string answerKey, int k)
    {
        int i = 0;
        int j = 0;
        int n = answerKey.length();

        int maxi = INT_MIN;
        int count = 0;

        while (i < n)
        {
            if (answerKey[i] == 'F')
            {
                count++;
            }

            while (count > k)
            {
                if (answerKey[j] == 'F')
                {
                    count--;
                }
                j++;
            }

            maxi = max(maxi, i - j + 1);
            i++;
        }
        return maxi;
    }
    int falsecount(string answerKey, int k)
    {
        int i = 0;
        int j = 0;
        int n = answerKey.length();

        int maxi = INT_MIN;
        int count = 0;

        while (i < n)
        {
            if (answerKey[i] == 'T')
            {
                count++;
            }

            while (count > k)
            {
                if (answerKey[j] == 'T')
                {
                    count--;
                }
                j++;
            }

            maxi = max(maxi, i - j + 1);
            i++;
        }
        return maxi;
    }
    int maxConsecutiveAnswers(string answerKey, int k)
    {

        int maxi = INT_MIN;

        int t = truecount(answerKey, k);
        int f = falsecount(answerKey, k);

        maxi = max(t, f);
        return maxi;
    }
};