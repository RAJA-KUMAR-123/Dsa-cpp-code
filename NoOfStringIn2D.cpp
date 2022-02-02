#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,string s,char ch[6][6],int size,int idx)
{
    int found=0;

    if(i>=0 && j>=0 &&  i<6 && j<6 && s[idx]==ch[i][j])
    {
        char temp=s[idx];
        ch[i][j]=0;
        idx += 1;

        if(idx==size){
            found =1;
        }
        else{
            found +=solve(i+1,j,s,ch,size,idx);
            found +=solve(i-1,j,s,ch,size,idx);
            found +=solve(i,j+1,s,ch,size,idx);
            found +=solve(i,j-1,s,ch,size,idx);
        }
        ch[i][j]=temp;
    }
    return found;
}
int main()
{
   string s="GEEKS";
  char ch[6][6]={
      {'D','D','D','G','o','D'},
      {'D','D','D','E','o','S'},
      {'D','S','K','E','o','K'},
      {'D','D','D','G','o','E'},
      {'D','D','D','G','o','E'},
      {'D','D','D','G','D','G'},
  };
  int ans=0;
  int size=5;  // size of "GEEKS"

  for(int i=0;i<6;i++){
    for(int j=0;j<6;j++)
    {
        ans+=solve(i,j,s,ch,size,0);
    }
  }
  cout<<ans;

  return 0;
}
