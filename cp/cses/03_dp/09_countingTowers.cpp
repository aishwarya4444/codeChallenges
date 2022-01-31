/*
https://cses.fi/problemset/task/2413
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int t, n;
ll dp[1000001][2];
int h[101];
const int mod = 1e9+7;

int main() {
	cin>>t;
	for(int i=0; i<t; i++) {
		cin>>h[i];
		n = max(n, h[i]);
	}

	dp[1][0] = 1;
	dp[1][1] = 1;
	for(int i=2; i<=n; i++) {
		dp[i][0] = (1LL*dp[i-1][1] + 4*dp[i-1][0]) % mod;
		dp[i][1] = (1LL*2*dp[i-1][1] + dp[i-1][0]) % mod;
	}

	for(int i=0; i<t; i++) {
		n = h[i];
		cout<<(1LL*dp[n][0] + dp[n][1]) % mod<<endl;
	}

	return 0;
}
