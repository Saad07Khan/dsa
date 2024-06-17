int countStudents(vector<int>& arr, int mid)
{
    int students=1;
    long long pages=0;

    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]+pages<=mid)
        {
            pages+=arr[i];

        }
        else
        {
            students+=1;
            pages=arr[i];
        }
    }

    return students;
}

int findPages(vector<int>& arr, int n, int m) {
    if (m > n) return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high) {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return low;
}