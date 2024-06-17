class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {

        int k = m + n - 1;
        int j = n - 1;
        int i = m - 1;

        while (j >= 0)
        {
            if (i >= 0 && nums1[i] > nums2[j])
            {
                nums1[k] = nums1[i];
                i--;
                k--;
            }

            else
            {
                nums1[k] = nums2[j];
                j--;
                k--;
            }
        }
    }
};

 int i=0;
        int j=0;
        int n= s.length();
        int count=0;
        int maxi=0;

        while(i<n)
        {
            if(s[i]=='B')
            {
                count++;
            }

            while(count>k)
            {
                if(s[j]=='B')
                {
                    count--;
                }
                j++;
            }

            maxi=max(maxi,i-j+1);
            i++;
        }