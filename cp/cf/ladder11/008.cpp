/*
https://codeforces.com/problemset/problem/281/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	string s;

	cin>>s;


	if(s[0]>='a' && s[0]<='z') {
		s[0] -= 32;
	}

	cout<<s;

	return 0;
}
