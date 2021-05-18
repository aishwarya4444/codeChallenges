/*
https://codeforces.com/problemset/problem/59/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

void toUpper(char c) {
	if(c>='a' && c<='z') {
		c -= 32;
	}
	cout<<c;
}

void toLower(char c) {
	if(c>='A' && c<='Z') {
		c += 32;
	}
	cout<<c;
}

int main() {
	string s;
	int upper=0, lower=0;

	cin>>s;

	for(auto ch: s) {
		if(ch>='A' && ch<='Z') {
			upper++;
		} else {
			lower++;
		}
	}

	for(auto ch: s) {
		if(upper>lower) {
			toUpper(ch);
		} else {
			toLower(ch);
		}
	}

	return 0;
}
