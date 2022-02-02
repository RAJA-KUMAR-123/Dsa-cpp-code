#include"bits/stdc++.h"

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setbits(x) builtin_popcount(x)

int main()
{
    int n;
    cout<<"Enter the number - ";
    cin >>n;

    vi a(n);

    rep(i,0,n)
    {


        cout<<"Enter the number:- ";
        cin>>a[i];
    }

    int curr=0 ,  MaxTillNow=0;
    rep(i,0,n)
    {
        curr+=a[i];
        MaxTillNow = max(curr,MaxTillNow);

        if(curr<0)
        {
            curr=0;
        }
    }

    cout<<"max no sum :- "<<MaxTillNow<<endl;
}
