/*
https://cses.fi/problemset/task/2166/
https://usaco.guide/problems/cses-2166-prefix-sum-queries/solution
https://www.geeksforgeeks.org/maximum-prefix-sum-given-range/

Given an array of n integers, your task is to process q queries of the following types:
update the value at position k to u
what is the maximum prefix sum in range [a,b]?

Input
The first input line has two integers n and q: the number of values and queries.
The second line has n integers x1,x2,…,xn: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 k u" or "2 a b".

Output
Print the result of each query of type 2.

Constraints
1≤n,q≤2⋅105
−109≤xi,u≤109
1≤k≤n
1≤a≤b≤n
Example

Input:
8 4
1 2 -1 3 1 -5 1 4
2 2 6
1 4 -2
2 2 6
2 3 4

Output:
5
2
0
*/


#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct psNode {
	ll sum, prefix;
	psNode(ll _sum, ll _prefix) {
		sum = _sum;
		prefix = _prefix;
	}
};

vector<psNode> tree;
int N;

psNode query(int node, int node_lo, int node_hi, int query_lo, int query_hi) {
	if(query_hi<node_lo || query_lo>node_hi) {
		return {0, 0};
	}
	// [query_lo .. [node_lo, node_hi] .. query_hi]
	if(node_lo>=query_lo && node_hi<=query_hi) {
		return tree[node];
	}

	int last_in_left = (node_lo+node_hi)/2;
	psNode left = query(2*node, node_lo, last_in_left, query_lo, query_hi);
	psNode right = query(2*node+1, last_in_left+1, node_hi, query_lo, query_hi);
	return {left.sum+right.sum, max(left.prefix, left.sum+right.prefix)};
}

void update(int node, int x) {
	tree[node] = {x, x};
	for(int i=node/2; i>=1; i/=2) {
		tree[i].sum = tree[2*i].sum+tree[2*i+1].sum;
		tree[i].prefix = max(tree[2*i].prefix , tree[2*i].sum+tree[2*i+1].prefix);
	}
}

int main() {
	int n, q;
	ll x;

	cin>>n>>q;
	N = n;
	while(__builtin_popcount(N) != 1) {
		N++;
	}
	tree.assign(2*N, {0, 0});
	for(int i=0; i<n; i++) {
		cin>>x;
		tree[N+i] = {x, max(0LL, x)};
	}

	for(int i=N-1; i>=1; i--) {
		tree[i].sum = tree[2*i].sum+tree[2*i+1].sum;
		tree[i].prefix = max(tree[2*i].prefix , tree[2*i].sum+tree[2*i+1].prefix);
	}

	for(int i=0; i<q; i++) {
		int type, k, u, a, b;
		cin>>type;
		if(type==1) {
			cin>>k>>u;
			k--;
			update(N+k, u);
		} else {
			cin>>a>>b;
			a--;
			b--;
			cout<<query(1, 0, N-1, a, b).prefix<<'\n';
		}
	}
}
