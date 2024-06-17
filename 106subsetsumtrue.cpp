
bool subsetsum(int i, vector<int> &temp, vector<int> &ans, int s, vector<int> &a, int n, int k)
{
    if (i == n)
    {
        if (s == k)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    temp.push_back(a[i]);
    s += a[i];
    if (subsetsum(i + 1, temp, ans, s, a, n, k) == true)
    {
        return true;
    }

    s -= a[i];
    temp.pop_back();
    if (subsetsum(i + 1, temp, ans, s, a, n, k) == true)
    {
        return true;
    }
    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    vector<int> ans;
    vector<int> temp;
    subsetsum(0, temp, ans, 0, a, n, k);
}