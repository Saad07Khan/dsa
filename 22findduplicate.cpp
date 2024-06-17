class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int low = 1, high = nums.size() - 1, cnt;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            cnt = 0;
            // cnt number less than equal to mid
            for (int n : nums)
            {
                if (n <= mid)
                    ++cnt;
            }

            // for (int i = 0; i < nums.size(); i++)
            // {
            //     int n = nums[i];
            //     if (n <= mid)
            //     {
            //         cnt++;
            //     }
            // }

            // binary search on left
            if (cnt <= mid)
                low = mid + 1;
            else
                // binary search on right
                high = mid - 1;
        }
        return low;
    }
    // for github repository link go to my profile.
};

// If cnt (the count of elements less than or equal to mid) is less than or equal to mid, it means that the duplicates must be in the right half of the range. This is because in a sorted array of unique integers, if there are more elements than the current mid value in the range from 1 to mid, it's an indication that there must be duplicates.

// If cnt is greater than mid, it implies that there are duplicates in the left half of the range. This is because if there are more elements than the current mid value in the range from 1 to mid, it suggests that some of these elements must be duplicates.