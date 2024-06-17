class Solution {
public:

// O(m * log n). solution
int binarysearch(vector<int>& matrix, int target)
{
    int low=0;
    int high=matrix.size()-1;

    while(low<=high)
    {
        int mid=(low+high)/2;
        if(matrix[mid]==target)
        {
            return mid;
        }

        else if(matrix[mid]<target)
        {
            low=mid+1;

        }
        else
        {
            high=mid-1;
        }
    }
    return -1;
}


    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for (int i = 0; i < matrix.size(); i++) {
            int check = binarysearch(matrix[i], target);
            if (check!=-1) {
                return true;
            }
        }
        return false;
    }
};



