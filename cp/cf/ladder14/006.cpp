/*
https://codeforces.com/problemset/problem/141/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	string s;
	vector<int> freq(26, 0);

	cin>>s;
	for(char ch: s) {
		freq[ch-'A']++;
	}

	cin>>s;
	for(char ch: s) {
		freq[ch-'A']++;
	}

	cin>>s;
	for(char ch: s) {
		freq[ch-'A']--;
	}

	for(int val: freq) {
		if(val!=0) {
			cout<<"NO";
			return 0;
		}
	}

	cout<<"YES";

	return 0;
}
