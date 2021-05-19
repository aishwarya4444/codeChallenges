/*
https://codeforces.com/problemset/problem/61/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	string s1, s2;
	int N, n, count;

	cin>>s1>>s2;

	N = s1.size();

	for(n=0; n<N; n++) {
		count = 0;
		if(s1[n]=='1') {
			count++;
		}
		if(s2[n]=='1') {
			count++;
		}
		cout<<count%2;
	}

	return 0;
}
