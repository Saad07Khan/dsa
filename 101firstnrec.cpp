#include <bits/stdc++.h>
using namespace std;
//sum of first n numbers using functional recursion

int firstn(int n)
{

    if(n==0)
    {
        return 0;
    }

    return n + firstn(n-1);

}



int main()
{
    int n;
    cout<<"Enter no: ";
    cin>>n;
    int sum = firstn(n);
    cout<<sum;
    return 0;
}