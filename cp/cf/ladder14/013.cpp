/*
https://codeforces.com/problemset/problem/219/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int k;
	string s, res;
	map<char, int> m;

	si(k);
	cin>>s;

	for(auto ch: s) {
		m[ch]++;
	}

	for(auto entry: m) {
		if(entry.second%k != 0) {
			cout<<"-1";
			return 0;
		}
		res += string(entry.second/k, entry.first);
	}

	while(k--) {
		cout<<res;
	}


	return 0;
}
