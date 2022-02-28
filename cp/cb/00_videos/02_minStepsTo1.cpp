// https://www.spoj.com/problems/MST1/

#include<bits/stdc++.h>
using namespace std;

int dp[20000001];

int solve(int n) {
	if(n==1) return 0;

	if(dp[n] != -1) {
		return dp[n];
	}

	int ans = solve(n-1);

	if(n%2 == 0) {
		ans = min(ans, solve(n/2));
	}

	if(n%3 == 0) {
		ans = min(ans, solve(n/3));
	}

	return dp[n] = 1+ans;
}

void bottomUp() {
	memset(dp, 0, sizeof dp);
	for(int i=2; i<=20000000; i++) {
		dp[i] = dp[i-1];
		if(i%2==0) {
			dp[i] = min(dp[i], dp[i/2]);
		}
		if(i%3==0) {
			dp[i] = min(dp[i], dp[i/3]);
		}
		dp[i] += 1;
	}
}

int main() {
	int t, n;

	// memset(dp, -1, sizeof dp);
	// solve(20000000);
	bottomUp();

	cin>>t;

	for(int tcase=1; tcase<=t; tcase++) {
		cin>>n;

		cout<<"Case "<<tcase<<": "<<dp[n]<<endl;
	}

	return 0;
}
