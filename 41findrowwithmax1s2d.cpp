int firstoccurence(vector<int>& matrix, int size, int one)
{
    int first=size; //since if target not available then return the last index
    int low=0;
    int high= matrix.size()-1;

    while(low<=high)
    {
        int mid=(low+high)/2;
        if(matrix[mid]==one)
        {
            first=mid;
            high=mid-1;
        }
        else if(matrix[mid]<one)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }

    return first;
}

//or use lowerbound
// int lowerbound(vector<int>& nums, int size, int x)
// {
//     int low=0;
//     int high= size-1;
//     int index=size;

//     while(low<=high)
//     {
//         int mid=(low+high)/2;
//         if(nums[mid]>=x)
//         {
//             index=mid;
//             high=mid-1;
//         }
//         else
//         {
//             low=mid+1;
//         }
//     }
//     return index;
// }


int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int cntmax=0;
    int index=-1;
    for(int i=0;i<n;i++)
    {
        int cntones= m- firstoccurence(matrix[i], m, 1);

        if(cntones>cntmax)
        {
            cntmax=cntones;
            index=i;
        }

        
    }
    return index;
}