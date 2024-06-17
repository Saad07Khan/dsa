#include <bits/stdc++.h>
using namespace std;

void printoneton(int i,int n)
{
   if(i<1)
   {
    return;
   }

   printoneton(i-1,n);
   cout<<i;
}


int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    printoneton(n,n);
}