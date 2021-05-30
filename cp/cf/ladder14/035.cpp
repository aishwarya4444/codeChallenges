/*
https://codeforces.com/problemset/problem/433/B
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int const N=1e5;
ll a[N];
ll dp_sorted[N+1];
ll dp_unsorted[N+1];

int main() {
	int n, m;

	cin>>n;

	for(int i=0; i<n; i++) {
		cin>>a[i];
		dp_unsorted[i+1] = dp_unsorted[i]+a[i];
	}

	sort(a, a+n);

	for(int i=0; i<n; i++) {
		dp_sorted[i+1] = dp_sorted[i]+a[i];
	}

	cin>>m;
	while(m--) {
		int type, l, r;
		cin>>type>>l>>r;
		if(type==1) {
			cout<<dp_unsorted[r]-dp_unsorted[l-1]<<'\n';
		} else {
			cout<<dp_sorted[r]-dp_sorted[l-1]<<'\n';
		}
	}

	return 0;
}