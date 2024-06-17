#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;

int find_min(int arr[], int n, int m)
{
    if(m==0 || n==0)
        return 0;

    sort(arr,arr+n); // sort requires 0th index and the next index of last element

    if(m>n)
        return -1;

    int min_diff = INT_MAX;


    for(int i=0; i+m-1<n;i++)            // as if window starts from i, window will end at i+m-1;
    {
        int diff = arr[i+m-1]-arr[i];
        if (diff<min_diff)
        {
            min_diff=diff;
        }

    }
    return min_diff;
}

int main()
{
    int arr[] = { 12, 4,  7,  9,  2,  23, 25, 41, 30,
                  40, 28, 42, 30, 44, 48, 43, 50 };
    int m = 7; // Number of students
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "
         << find_min(arr, n, m);
    return 0;
}
 