// https://www.codechef.com/MALI2017/problems/MAXCOST

#include<bits/stdc++.h>
using namespace std;

int dp[2000][2000];
int c[2000];

int solve(int lo, int hi, int year) {
	if(lo > hi) return 0;
	if(lo == hi) return year*c[lo];

	if(dp[lo][hi] != -1) {
		return dp[lo][hi];
	}

	int start = c[lo]*year + solve(lo+1, hi, year+1);

	int last = c[hi]*year + solve(lo, hi-1, year+1);

	return dp[lo][hi] = max(start, last);
}

int main() {
	int n;

	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>c[i];
	}

	memset(dp, -1, sizeof dp);

	cout<<solve(0, n-1, 1);

	return 0;
}
