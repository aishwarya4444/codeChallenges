/*
https://codeforces.com/problemset/problem/272/C

Lets L will be the answer after last block, last block was (w1, h1), next block is (w2, h2).
Next answer will be max(L+h1, A[w2]), where A — given array.
At the beginning we can suppose that L = 0, w1 = 0, h1 = 0.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=1e5;
ll height[N];

int main() {
	int n, m, a;
	ll w, h, h0=0, H=0;

	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a;
		height[i] = a;
	}

	cin>>m;
	while(m--) {
		cin>>w>>h;
		H = max(H+h0, height[w]);
		h0 = h;
		cout<<H<<'\n';
	}

	return 0;
}