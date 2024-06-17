#include <iostream>
#include <vector>
#include <algorithm> // Include this for std::sort
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    if (a.first == b.first)
    {
        return a.second > b.second;   // with this we sort in decresing order for both first and second element
    }
    return a.first > b.first;
}   
//comp used to sort as we want when there is custom input ie: strings num together etc
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }

    cout<<" "<<endl;

    sort(v.begin(), v.end(), comp);
    for (int i = 0; i < n; i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }

    return 0;
}
