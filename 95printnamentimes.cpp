// using recursion  
#include<bits/stdc++.h>
using namespace std;

void func(int i,int n)
{
    if(i>n) // for i =1 it wont be executed
    return;

    cout<<"Name"<<endl;// this executes and name is printed
    func(i+1,n); // f(2,4) is called
}

int main(){
  
  // Here, let’s take the value of n to be 4.
  int n = 4;
  func(1,n);
  return 0;

}