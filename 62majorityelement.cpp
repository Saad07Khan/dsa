#include <bits/stdc++.h>
using namespace std;
//majority element is that element in an array whose count is greatest in array and greater than n/2 
//main takeaway is how to traverse array using two for loops
// when returning indexes initialize value of index as -1
int majority(int arr[],int n)
{
    
    int maxi=0;
    int index=-1;

    for(int i=0;i<n;i++)
    {
        int count=0;
        for(int j=0;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
            }

        }
        if(count>maxi)
        {
            maxi=count;
            index=i;
        }
        
    }


    if(maxi>n/2)
    {
        cout<<arr[index]<<endl;
    }
    else
    {
        cout<<"No majority element"<<endl;
    }
}


int main()
{
    int arr[] = { 1, 1, 2, 1, 3, 5, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function calling
    majority(arr,n);
 
    return 0;
}

//label control with examples
