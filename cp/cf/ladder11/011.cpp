/*
https://codeforces.com/problemset/problem/80/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int getNext(int num) {
	int n;
	vector<bool> p(51, false);

	p[2] = true;
	for(int i=3; i<=50; i+=2) {
		p[i] = true;
	}

	for(int i=3; i*i<=50; i+=2) {
		if(p[i]) {
			for(int j=i*i; j<=50; j+=i) {
				p[j] = false;
			}
		}
	}

	for(n=0; n<=50; n++) {
		if(p[n] && n==num) {
			break;
		}
	}

	for(n=n+1; n<=50; n++) {
		if(p[n]) {
			return n;
		}
	}

	return -1;
}

int main() {
	int n, m;

	cin>>n>>m;

	if(m==getNext(n)) {
		cout<<"YES";
	} else {
		cout<<"NO";
	}

	return 0;
}
