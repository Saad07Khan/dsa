#include <bits/stdc++.h>
using namespace std;



void printn(int i, int n)
{
    if(i>n)
    {
        return;
    }

    cout<<i;
    printn(i+1,n);

}
int main()
{

    int n;
    cout << "Enter the number: ";
    cin >> n;
    printn(1,n);

    return 0;
}