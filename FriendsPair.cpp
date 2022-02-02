/*
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
    cin>>n;


    }
    cout<<dp[n]<<endl;

}
*/

// C++ program for solution of
// friends pairing problem
#include <bits/stdc++.h>
using namespace std;

// Returns count of ways n people
// can remain single or paired up.
int countFriendsPairings(int n)
{
	int dp[n + 1];

	// Filling dp[] in bottom-up manner using
	// recursive formula explained above.
	for (int i = 0; i <= n; i++) {
		if (i <= 2)
			dp[i] = i;
		else
			dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
	}

	return dp[n];
}

// Driver code
int main()
{
	int n;
	cin>>n;
	cout << countFriendsPairings(n) << endl;
	return 0;
}


