vector<int> superiorElements(vector<int> &a)
{
    vector<int> ans;
    int n = a.size();
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        // If the current element is greater than the maximum encountered so far, add it to the result vector.
        if (a[i] > maxi)
        {
            ans.push_back(a[i]);
        }

        // Update the maximum element encountered.
        maxi = max(maxi, a[i]);
    }

    // Return the vector containing superior elements.
    return ans;
}