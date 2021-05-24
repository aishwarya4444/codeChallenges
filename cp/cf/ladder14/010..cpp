/*
https://codeforces.com/problemset/problem/96/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	string s;

	cin>>s;

	int one=0, zero=0;

	for(auto ch: s) {
		if(ch=='0') {
			zero++;
			one = 0;
		} else {
			one++;
			zero = 0;
		}
		if(one==7 || zero==7) {
			cout<<"YES";
			return 0;
		}
	}

	cout<<"NO";

	return 0;
}
