/*
https://cses.fi/problemset/task/1636
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[102][1000002];
const int mod = 1e9+7;
int coins[101];

// top down takes more time
int solve(int pos, int x, int n) {
	if(x==0) {
		return 1;
	}

	if(x<0 || pos==n) {
		return 0;
	}

	if(dp[pos][x]!=-1) {
		return dp[pos][x];
	}

	ll ans = solve(pos+1, x, n);
	if(x>=coins[pos]) ans = (ans + solve(pos, x-coins[pos], n)) % mod;

	return dp[pos][x] = ans;
}

// bottom up takes less time
void getAns(int n, int x) {
	// memset(dp, 0, sizeof dp);
	for(int pos=0; pos<n; pos++) {
		for(int sum=0; sum<=x; sum++) {
			if(sum==0) dp[pos][sum] = 1;
			else {
				if(pos>0) {
					dp[pos][sum] = dp[pos-1][sum];
				}
				if(sum>=coins[pos]) {
					dp[pos][sum] = (1LL*dp[pos][sum] + dp[pos][sum-coins[pos]])%mod;
				}
			}
		}
	}
}

int main() {
	int n, x;

	cin>>n>>x;

	for(int i=0; i<n; i++) {
		cin>>coins[i];
	}

	// bottom up
	getAns(n, x);
	cout<<dp[n-1][x];

	// top down
	// sorting in descending order so that big numbers are subtracted first
	// sort(coins, coins+n, greater<int>());
	/* sorting is not needed */
	// memset(dp, -1, sizeof dp);
	// cout<<solve(0, x, n);

	return 0;
}
