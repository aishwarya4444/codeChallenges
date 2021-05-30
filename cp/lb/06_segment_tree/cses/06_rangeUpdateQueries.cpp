/*

https://cses.fi/problemset/task/1651

Given an array of n integers, your task is to process q queries of the following types:
increase each value in range [a,b] by u
what is the value at position k?

Input
The first input line has two integers n and q: the number of values and queries.
The second line has n integers x1,x2,…,xn: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 a b u" or "2 k".

Output
Print the result of each query of type 2.

Constraints
1≤n,q≤2⋅105
1≤xi,u≤109
1≤k≤n
1≤a≤b≤n
Example

Input:
8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4

Output:
5
6
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

vector<ll> tree;
int N;

// ll f(int node, int node_lo, int node_hi, int query_lo, int query_hi, int val) {
// 	if(query_hi<node_lo || query_lo>node_hi) {
// 		return 0;
// 	}
// 	// [query_lo .. [node_lo, node_hi] .. query_hi]
// 	if(node_lo>=query_lo && node_hi<=query_hi) {
// 		if(val!=-1) {
// 			tree[node] += val;
// 		}
// 		return tree[node];
// 	}

// 	int last_in_left = (node_lo+node_hi)/2;
// 	ll lsum = f(2*node, node_lo, last_in_left, query_lo, query_hi, val);
// 	ll rsum = f(2*node+1, last_in_left+1, node_hi, query_lo, query_hi, val);
// 	return lsum+rsum+tree[node];
// }

ll query(int node, int node_lo, int node_hi, int query_lo, int query_hi) {
	if(query_hi<node_lo || query_lo>node_hi) {
		return 0;
	}
	// [query_lo .. [node_lo, node_hi] .. query_hi]
	if(node_lo>=query_lo && node_hi<=query_hi) {
		return tree[node];
	}

	int last_in_left = (node_lo+node_hi)/2;
	ll lsum = query(2*node, node_lo, last_in_left, query_lo, query_hi);
	ll rsum = query(2*node+1, last_in_left+1, node_hi, query_lo, query_hi);
	return lsum+rsum+tree[node];
}

void update(int node, int node_lo, int node_hi, int query_lo, int query_hi, int val) {
	if(query_hi<node_lo || query_lo>node_hi) {
		return;
	}
	// [query_lo .. [node_lo, node_hi] .. query_hi]
	if(node_lo>=query_lo && node_hi<=query_hi) {
		tree[node] += val;
		return;
	}

	int last_in_left = (node_lo+node_hi)/2;
	update(2*node, node_lo, last_in_left, query_lo, query_hi, val);
	update(2*node+1, last_in_left+1, node_hi, query_lo, query_hi, val);
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

	for(int i=0; i<q; i++) {
		int type, k, u, a, b;
		cin>>type;
		if(type==1) {
			cin>>a>>b>>u;
			a--;
			b--;
			update(1, 0, N-1, a, b, u);
		} else {
			cin>>k;
			k--;
			cout<<query(1, 0, N-1, k, k)<<'\n';
		}
	}
}
