#include<iostream>
using namespace std;

int getLength(char name[])
{
    int count = 0;
    for(int i=0; name[i]!='\0';i++)
    {
        count++;
    }
    return count;
}
string reverse(char name[], int l)
{
    int s = 0;
    int e= l-1;
    while(s<=e)
    {
        swap(name[s++],name[e--]);
        // s++;
        // e++;
    }

    return name;
}

int main()
{
    char name[20];
    cout<<"Enter your name: "<<endl;
    cin>>name;
    cout<< "Your name is ";
    cout<<name<<endl;
    int l = getLength(name);

    reverse(name,l);
    cout<<name<<endl;


    
    return 0;
}


