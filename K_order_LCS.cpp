#include"bits/stdc++.h"
using namespace std;



int Solve(int i,int j,int k)
{
  if(i==n||j==m)
  {
     return 0;
  }
  int c1(0),c2(0),c3(0);

  if(a[i]==b[j])
  {
    c1=1+Solve(i+1,j+1,k);
  }
  if(k>0)
  {
    c2=1+Solve(i+1,j+1,k-1);
  }
  c3=max(Solve(i+1,j,k),Solve(i,j+1,k));

  int ans = max({c1,c2,c3});

  return ans;
}
int main()
{
  int n,m,k;
   cin>>n>m>>k;
  vector<int> a,b;



 a=vector<int>(n);
 b=vector<int>(m);

 for(auto &i:a)
     cin>>i;

for(auto &i:b)
     cin>>i;

cout<<Solve(0,0,k)<<endl;


}
