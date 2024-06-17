#include <bits/stdc++.h>
using namespace std;

void printntoone(int i,int n)
{
    if(i>n)
    {
        return;
    }

    printntoone(i+1,n);
    cout<<i;
}

int main()
{
    int n;
    cout << "Enter the number: ";
    cin >> n;
    printntoone(1,n);
}