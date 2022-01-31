/*
https://cses.fi/problemset/task/1746
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
int x[100001];
int dp[100001][101];
const int mod = 1e9+7;

int solve(int pos, int prev) {
	if(pos==n) {
		return 1;
	}

	if(dp[pos][prev] != -1) {
		return dp[pos][prev];
	}

	int ans = 0;
	// if current value is 0
	if(x[pos]==0) {
		for(int diff: {-1, 0, 1}) {
			int curr = prev+diff;
			if(curr>=1 && curr<=m) {
				ans = (1LL*ans + solve(pos+1, curr)) % mod;
			}
		}
	}
	// current value is not zero
	else {
		if(abs(prev-x[pos])<2) {
			ans = solve(pos+1, x[pos]);
		}
	}

	return dp[pos][prev] = ans;
}

int main() {
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>x[i];
	}
	memset(dp, -1, sizeof dp);

	int res = 0;
	// if first element is zero try all values
	if(x[0]==0) {
		for(int curr=1; curr<=m; curr++) {
			res = (1LL*res + solve(1, curr)) % mod;
		}
	} else {
		res = solve(1, x[0]);
	}

	cout<<res;

	return 0;
}
