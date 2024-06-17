#include <bits/stdc++.h>
using namespace std;

printoneton(int n)
{
    if(n<1)
    {
        return n;
    }

    cout<<n;

    printoneton(n-1);

}






int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    printoneton(n);
}