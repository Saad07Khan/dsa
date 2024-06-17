#include <bits/stdc++.h>
vector<int> rotateArray(vector<int> &arr, int n)
{

    int temp = arr[0];

    for (int i = 1; i < n; i++)
    {
        swap(arr[i], arr[i - 1]);
    }

    arr[n - 1] = temp;

    return arr;
}
