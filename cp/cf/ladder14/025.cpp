/*
https://codeforces.com/problemset/problem/388/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int n, k=0;
	vector<int> a;

	si(n);
	a.assign(n, 0);

	for(int &num: a) {
		si(num);
	}

	sort(a.begin(), a.end());

	for(int i=0; i<n; i++) {
		if(k*(a[i]+1) <= i) {
			k++;
		}
	}

	cout<<k;

	return 0;
}
