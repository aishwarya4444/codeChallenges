/*

https://cses.fi/problemset/task/1649

Given an array of n integers, your task is to process q queries of the following types:
update the value at position k to u
what is the minimum value in range [a,b]?

Input
The first input line has two integers n and q: the number of values and queries.
The second line has n integers x1,x2,…,xn: the array values.
Finally, there are q lines describing the queries. Each line has three integers: either "1 k u" or "2 a b".

Output
Print the result of each query of type 2.

Constraints
1≤n,q≤2⋅105
1≤xi,u≤109
1≤k≤n
1≤a≤b≤n
Example

Input:
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 2 3
2 1 4

Output:
2
1
3
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
		return INT_MAX;
	}
	// [query_lo .. [node_lo, node_hi] .. query_hi]
	if(node_lo>=query_lo && node_hi<=query_hi) {
		return tree[node];
	}

	int last_in_left = (node_lo+node_hi)/2;
	return min(f(2*node, node_lo, last_in_left, query_lo, query_hi),
		f(2*node+1, last_in_left+1, node_hi, query_lo, query_hi));
}

void update(int node, int val) {
	tree[node+N] = val;
	for(int i=(node+N)/2; i>=1; i/=2) {
		tree[i] = min(tree[2*i], tree[2*i+1]);
	}
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
		tree[i] = min(tree[2*i], tree[2*i+1]);
	}

	for(int i=0; i<q; i++) {
		int type, k, u, lo, hi;
		cin>>type;
		if(type==1) {
			cin>>k>>u;
			k--;
			update(k, u);
		} else {
			cin>>lo>>hi;
			lo--;
			hi--;
			cout<<f(1, 0, N-1, lo, hi)<<'\n';
		}
	}
}
