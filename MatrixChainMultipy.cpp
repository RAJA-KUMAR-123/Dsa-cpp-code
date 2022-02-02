

#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 102 , MOD = 1e9+7;

int a[N];
int dp[N][N];
/*

// memorization of Matrix chain Multiplication


int Mcm(  int i ,int j)
{
    if(i==j)
    {
        return 0;
    }
    // val
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }
    dp[i][j] = MOD;

    for( int k=i ; k<j ; k++)
    {
        dp[i][j]=min(dp[i][j], Mcm(i,k) + Mcm(k+1,j) + a[i-1]*a[k]*a[j]);
    }
    return dp[i][j];
}
signed main()
{
    int n;
    cin >> n;

    memset(dp,-1,sizeof dp);

    for(int i=0;i<n;i++)
    {
        cin >> a[i];
    }

    cout << Mcm(1,n-1) << endl;
    return 0;
}
*/


// tabulation method but wrong ans
signed main()
{
  int n;
  cin>>n;

  for(int i=0;i<n;i++)
  {
      cin >> a[i];
  }

  for(int i=1;i<n;i++)
  {

    dp[i][i]=0;
  }

  for( int l=2;l<n;l++)
  {
      for(int i=0;i<n-l+1;i++)
      {
          int j = i+1-1;
          dp[i][j]=MOD;
          for(int k=i;k<j;k++)
          {
              dp[i][j]=min(dp[i][j],dp[i][k] + dp[k+1][j]+a[i-1]*a[k]*a[j]);
          }

      }
  }


  cout << dp[1][n-1] << endl;
  return 0;

}
