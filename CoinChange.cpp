#include"bits/stdc++.h"

using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define ff first
#define ss second
#define setbits(x) builtin_popcount(x)

const int N = 1e3+2;

int coinchange( vi &a , int n , int x)
{
    if(x==0)
    {
        return 1;
    }
    if(x<0)
    {
        return 0;
    }
    if(n<=0)
    {
        return 0;
    }

    return coinchange(a,n, x-a[n-1]) + coinchange(a,n-1,x);
}
signed main()
{
    int n;
    cin >> n;

    vi a(n);

    rep(i,0,n)
     cin >> a[i];

     int x;
     cin >> x;

     cout << coinchange(a,n,x) << endl;

}
