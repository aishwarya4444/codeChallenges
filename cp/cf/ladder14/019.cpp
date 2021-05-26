/*
https://codeforces.com/problemset/problem/118/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;


int main() {
	string s;
	unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};

	cin>>s;

	for(char ch: s) {
		if(vowel.count(ch)) {
			continue;
		}
		cout<<'.';
		if(ch>='A' && ch<='Z') {
			ch = ch+' ';
		}
		cout<<ch;
	}

	return 0;
}
