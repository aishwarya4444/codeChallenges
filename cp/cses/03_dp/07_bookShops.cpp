/*
https://cses.fi/problemset/task/1158
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, x;
int h[1000]; // price
int s[1000]; // pages
int dp[1001][100001];
int _dp[100001];

// top down
int solve(int pos, int sum) {
	if(sum==0 || pos==n) {
		return 0;
	}

	if(dp[pos][sum] != -1) {
		return dp[pos][sum];
	}

	int buy = 0;
	int skip = solve(pos+1, sum); // not buying the book
	if(sum>=h[pos]) { // buying the book
		buy = s[pos] + solve(pos+1, sum-h[pos]);
	}

	return dp[pos][sum] = max(skip, buy);
}

int main() {
	cin>>n>>x;

	for(int i=0; i<n; i++) {
		cin>>h[i];
	}

	for(int i=0; i<n; i++) {
		cin>>s[i];
	}

	memset(_dp, 0, sizeof _dp);

	// cout<<solve(0, x);


	// bottom up
	for(int pos=0; pos<n; pos++) {
		for(int cost=x; cost>=0; cost--) {
			if(cost>=h[pos]) {
				_dp[cost] = max(_dp[cost], s[pos]+_dp[cost-h[pos]]);
			}
		}
	}

	cout<<_dp[x];

	return 0;
}
