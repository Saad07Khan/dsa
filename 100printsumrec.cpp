// using parameterized way
// sum of first n numbers
#include <bits/stdc++.h>
using namespace std;
void summ(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }

    summ(i - 1, sum + i);
}

int main()
{
    int n;
    cout << "Enter the Number: ";
    cin >> n;

    summ(n, 0);

    return 0;
}