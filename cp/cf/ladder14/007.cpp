/*
https://codeforces.com/problemset/problem/71/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int n;
	string s;

	si(n);
	while(n--) {
		cin>>s;
		if(s.size() <= 10) {
			cout<<s<<endl;
		} else {
			cout<<s[0]<<(s.size()-2)<<s[s.size()-1]<<endl;
		}
	}

	return 0;
}
