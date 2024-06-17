// brute force
//To make any array a palindrome, we can simply apply merge operation n-1 times where n is the size of the array (because a single-element array is always palindromic, similar to single-character string). In that case, the size of array will be reduced to 1. But in this problem, we are asked to do it in the minimum number of operations.

#include <bits/stdc++.h>
using namespace std;

int findMinOps(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int count = 0;

    while (low <= high)
    {
        if (arr[low] == arr[high])
        {
            low++;
            high--;
        }

        // If left element is greater, then
        // we merge right two elements

        else if (arr[low] > arr[high])
        {
            high--;
            arr[high] += arr[high + 1];
            count++;
        }
        // Else we merge left two elements
        else
        {
            low++;
            arr[low] += arr[low - 1];
            count++;
        }
    }

    return count;
}

int main()
{
    int arr[] = {11, 14, 15, 99};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Count of minimum operations is "
         << findMinOps(arr, n) << endl;
    return 0;
}