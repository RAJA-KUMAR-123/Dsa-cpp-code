#include"bits/stdc++.h"
using namespace std;

int dp[1001][1001];
int solve(string p,string s,int i,int j)
{
    if(i==-1 && j==-1)
    {
        return 1;
    }
    if(j==-1){
        for(int k=0;k<i;k++){
            if(p[k]!='*') return 0;
        }
        return 1;
    }
    if(i==-1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(dp[i]==s[j]||p[i]=='?') return dp[i][j]=solve(p,s,i-1,j-1);
    if(p[i]=='*'){
        int op1=solve(p,s,i-1,j);
        int op2=solve(p,s,i,j-1);
        return dp[i][j]= op1 || op2;
    }
    return dp[i][j]=0;
}

int main()
{
    string p,s;
    cin>>p>>s;
    memset(dp,-1,sizeof(dp));
    int x=solve(p,s,p.length()-1,s.length()-1);
    if(x==1){
        cout<<"yes\n";
    }
    else{
        cout<<"no\n";
    }
    return 0;
}
