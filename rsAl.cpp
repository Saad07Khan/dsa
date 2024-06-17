#include<iostream>
#include<cmath>

using namespace std;


long long modular(long long  base, long long exponent, long long mod)
{
    long long result=1;
     base = base % mod;
    while(exponent>0)
    {
        if(exponent%2==1)
        {
            result = result*base % mod;
        }

        exponent = exponent>>1;
        base = (base*base)%mod;
    }

    return result;
}

int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }

    return gcd(b,a%b);
}


long long rsakey(long long &d, long long phi, long long n, long long e)
{
    for(d=2;d<phi;d++)
    {
        if((d*e)%phi==1)
        {
            break;
        }
    }
   
}

long long rsaEncryption(long long message, long long e, long long n)
{
    long long temp = modular(message,e,n);
    return temp;
}

long long rsaDecryption(long long ct, long long d, long long n )
{
    return modular(ct,d,n);
}

int main()
{
    int p=3;
    int q=11;
    
    
    long long phi = (p-1)*(q-1);
    long long n = p*q;
    
    int message = 4;
    long long e=13;
    long long d;
    rsakey(d,phi,n,e);
    long long ct= rsaEncryption(message,e,n);
    cout<<ct<<endl;
    cout<<d<<endl;
    long long dt = rsaDecryption(ct,d,n);
    cout<<dt<<endl;

    return 0;

}
