/*
https://cses.fi/problemset/task/1638
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[1001][1001];
const int mod = 1e9+7;

int main() {
	int n;
	char ch;

	cin>>n;
	for(int r=1; r<=n; r++) {
		for(int c=1; c<=n; c++) {
			cin>>ch;
			if(ch=='.') {
				dp[r][c] = r==1&& c==1 ? 1 : (1LL*dp[r-1][c]+dp[r][c-1]) % mod;
			} else {
				dp[r][c] = 0;
			}
		}
	}

	cout<<dp[n][n];

	return 0;
}
