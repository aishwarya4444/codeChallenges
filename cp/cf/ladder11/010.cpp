/*
https://codeforces.com/problemset/problem/266/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	string s;
	int n, N, count=0;

	si(N);
	cin>>s;

	for(n=1; n<N; n++) {
		if(s[n-1]==s[n]) {
			count++;
		}
	}

	cout<<count;

	return 0;
}
