/*
https://codeforces.com/problemset/problem/285/C

The solution of the problem is rather simple.
Sort all integers a and then make from integer a[1] integer 1, from integer a[2] integer 2 and so on.
So, integer a[i] adds to the answer the value |a[i] - i|.
The answer should be count in 64-bit type.
You can simply guess why such solution is correct.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll const N=3*1e5+1;
ll a[N];

int main() {
	ll i, n, moves=0;

	cin>>n;
	for(i=1; i<=n; i++) {
		cin>>a[i];
	}

	sort(a+1, a+n+1);

	for(i=1; i<=n; i++) {
		moves += abs(a[i]-i);
	}

	cout<<moves;

	return 0;
}