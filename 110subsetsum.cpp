#include <bits/stdc++.h>
void subset(int i, int sum, vector<int> &num, vector<int> &ans)
{
    if (i == num.size())
    {
        ans.push_back(sum);
        return;
    }

    subset(i + 1, sum + num[i], num, ans); // pick
    subset(i + 1, sum, num, ans);          // not pick
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;

    subset(0, 0, num, ans);
    sort(ans.begin(), ans.end());

    return ans;
}
// another way
#include <bits/stdc++.h>
void subset(int i, int sum, vector<int> &num, vector<int> &ans)
{
    if (i == num.size())
    {
        ans.push_back(sum);
        return;
    }

    sum += num[i];

    subset(i + 1, sum, num, ans); // pick
    sum -= num[i];
    subset(i + 1, sum, num, ans); // not pick
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;

    subset(0, 0, num, ans);
    sort(ans.begin(), ans.end());

    return ans;
}