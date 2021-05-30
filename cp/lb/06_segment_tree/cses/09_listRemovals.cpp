/*

https://cses.fi/problemset/task/1749

You are given a list consisting of n integers. Your task is to remove elements from the list at given positions, and report the removed elements.

Input
The first input line has an integer n: the initial size of the list.
During the process, the elements are numbered 1,2,…,k where k is the current size of the list.
The second line has n integers x1,x2,…,xn: the contents of the list.
The last line has n integers p1,p2,…,pn: the positions of the elements to be removed.

Output
Print the elements in the order they are removed.

Constraints
1≤n≤2⋅105
1≤xi≤109
1≤pi≤n−i+1
Example

Input:
5
2 6 1 4 2
3 1 3 1 1

Output:
1 2 2 6 4

Explanation: The contents of the list are [2,6,1,4,2], [2,6,4,2], [6,4,2], [6,4], [4] and [].
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> tree;
int N;

void query(int node, int p, int &idx) {

	if(node>=N) {
		idx = node;
		return;
	}

	if(p<=tree[2*node]) {
		query(2*node, p, idx);
	} else {
		query(2*node+1, p-tree[2*node], idx);
	}
}

void update(int idx) {
	tree[idx] = 0;
	for(int i=idx/2; i>=1; i/=2) {
		tree[i] = tree[2*i] + tree[2*i+1];
	}
}

int main() {
	int n;
	vector<int> x;

	cin>>n;
	N = n;
	while(__builtin_popcount(N) != 1) {
		N++;
	}
	tree.assign(2*N, 0);
	x.assign(n, 0);
	for(int i=0; i<n; i++) {
		cin>>x[i];
		tree[N+i] = 1;
	}
	for(int i=N-1; i>=1; i--) {
		tree[i] = tree[2*i] + tree[2*i+1];
	}

	while(n--) {
		int p, idx=-1;
		cin>>p;
		query(1, p, idx);
		update(idx);
		cout<<x[idx-N]<<' ';
	}

	return 0;
}
