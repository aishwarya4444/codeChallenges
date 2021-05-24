/*
https://codeforces.com/problemset/problem/58/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {

	string s, h="hello";
	int r, c, S, H;

	cin>>s;
	S=s.size();
	H=h.size();

	vector<vector<int> > dp(S+1, vector<int>(H+1, 0));

	for(r=1; r<=S; r++) {
		for(c=1; c<=H; c++) {
			if(s[r-1]==h[c-1]) {
				dp[r][c] = 1+dp[r-1][c-1];
			} else {
				dp[r][c] = max(dp[r][c-1], dp[r-1][c]);
			}
		}
	}

	if(dp[S][H]==H) {
		cout<<"YES";
	} else {
		cout<<"NO";
	}

	return 0;
}
