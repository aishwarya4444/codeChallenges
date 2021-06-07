/*
https://codeforces.com/problemset/problem/152/C
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n, m;
	ll ans=1LL;
	int MOD = 1e9+7;
	string s;

	cin>>n>>m;

	set<char> st[m];

	for(int i=0; i<n; i++) {
		cin>>s;
		for(int j=0; j<m; j++) {
			st[j].insert(s[j]);
		}
	}

	for(int j=0; j<m; j++) {
		ans = (ans*st[j].size())%MOD;
	}

	cout<<ans;

	return 0;
}
