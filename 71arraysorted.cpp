int isSorted(int n, vector<int> a) {
    
    for(int i=0;i<n-1;i++)
    {
        if(a[i]<=a[i+1])
        {
            continue;
        }
        else
        {
            return 0;
        }

    }
    return 1;
}
