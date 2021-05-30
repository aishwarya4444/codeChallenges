/*

https://cses.fi/problemset/task/1650

Given an array of n integers, your task is to process q queries of the form: what is the xor sum of values in range [a,b]?

Input
The first input line has two integers n and q: the number of values and queries.
The second line has n integers x1,x2,…,xn: the array values.
Finally, there are q lines describing the queries.
Each line has two integers a and b: what is the xor sum of values in range [a,b]?

Output
Print the result of each query.

Constraints
1≤n,q≤2⋅105
1≤xi≤109
1≤a≤b≤n
Example

Input:
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3

Output:
3
0
6
4
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

vector<ll> tree;
int N;

ll f(int node, int node_lo, int node_hi, int query_lo, int query_hi) {
	if(query_hi<node_lo || query_lo>node_hi) {
		return 0;
	}
	// [query_lo .. [node_lo, node_hi] .. query_hi]
	if(node_lo>=query_lo && node_hi<=query_hi) {
		return tree[node];
	}

	int last_in_left = (node_lo+node_hi)/2;
	return (f(2*node, node_lo, last_in_left, query_lo, query_hi) ^
		f(2*node+1, last_in_left+1, node_hi, query_lo, query_hi));
}

int main() {
	int n, q;

	cin>>n>>q;
	N = n;
	while(__builtin_popcount(N) != 1) {
		N++;
	}
	tree.assign(2*N, 0);
	for(int i=0; i<n; i++) {
		cin>>tree[N+i];
	}
	for(int i=N-1; i>=1; i--) {
		tree[i] = (tree[2*i] ^ tree[2*i+1]);
	}

	while(q--) {
		int a, b;
		cin>>a>>b;
		a--;
		b--;
		cout<<f(1, 0, N-1, a, b)<<'\n';
	}
}
