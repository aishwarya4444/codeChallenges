/*
https://codeforces.com/problemset/problem/118/B
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int n;

	si(n);

	for(int i=0; i<=n; i++) {
		for(int j=1; j<=n-i; j++) {
			cout<<"  ";
		}
		cout<<0;
		for(int j=1; j<=i; j++) {
			cout<<' '<<j;
		}
		for(int j=i-1; j>=1; j--) {
			cout<<' '<<j;
		}
		if(i) {
			cout<<" 0";
		}
		cout<<endl;
	}

	for(int i=n-1; i>=0; i--) {
		for(int j=1; j<=n-i; j++) {
			cout<<"  ";
		}
		cout<<0;
		for(int j=1; j<=i; j++) {
			cout<<' '<<j;
		}
		for(int j=i-1; j>=1; j--) {
			cout<<' '<<j;
		}
		if(i) {
			cout<<" 0";
		}
		cout<<endl;
	}

	return 0;
}
