/*

https://cses.fi/problemset/task/1144
https://codeforces.com/blog/entry/77128
https://usaco.guide/problems/cses-1144-salary-queries/solution

A company has n employees with certain salaries.
Your task is to keep track of the salaries and process queries.

Input
The first input line contains two integers n and q: the number of employees and queries.
The employees are numbered 1,2,…,n.
The next line has n integers p1,p2,…,pn: each employee's salary.

After this, there are q lines describing the queries.
Each line has one of the following forms:
    ! k x: change the salary of employee k to x
    ? a b: count the number of employees whose salary is between a…b

Output
Print the answer to each ? query.

Constraints
1≤n,q≤2⋅105
1≤pi≤109
1≤k≤n
1≤x≤109
1≤a≤b≤109
Example

Input:
5 3
3 7 2 2 5
? 2 3
! 3 6
? 2 3

Output:
3
2
*/

#include <bits/stdc++.h>
using namespace std;

struct SalaryInfo {
	int sal;
	int maxSal;
	int minSal;
	int count;

	SalaryInfo(int _sal, int _maxSal, int _minSal, int _count) {
		sal = _sal;
		maxSal = _maxSal;
		minSal = _minSal;
		count = _count;
	}
};

vector<SalaryInfo> tree;
int N;

int query(int node, int a, int b) {
	// [a, b] ... [minSal, maxSal] ... [a, b]
	if(b<tree[node].minSal || a>tree[node].maxSal) {
		return 0;
	}

	// [a ... [minSal, maxSal] ... b]
	if(a<=tree[node].minSal && b>=tree[node].maxSal) {
		return tree[node].count;
	}

	if(node>=N) {
		return 0;
	}

	return query(2*node, a, b) + query(2*node+1, a, b);

}

void update(int node, int sal) {
	tree[node] = {sal, sal, sal, 1};
	for(int i=node/2; i>=1; i/=2) {
		tree[i].minSal = min(tree[2*i].minSal, tree[2*i+1].minSal);
		tree[i].maxSal = max(tree[2*i].maxSal, tree[2*i+1].maxSal);
	}
}

int main() {
	int n, q, sal;

	cin>>n>>q;
	N = n;
	while(__builtin_popcount(N) != 1) {
		N++;
	}
	tree.assign(2*N, {0, INT_MIN, INT_MAX, 0});
	for(int i=0; i<n; i++) {
		cin>>sal;
		tree[N+i] = {sal, sal, sal, 1};
	}
	for(int i=N-1; i>=1; i--) {
		tree[i].minSal = min(tree[2*i].minSal, tree[2*i+1].minSal);
		tree[i].maxSal = max(tree[2*i].maxSal, tree[2*i+1].maxSal);
		tree[i].count = tree[2*i].count + tree[2*i+1].count;
	}

	while(q--) {
		char type;
		int k, x, a, b;
		cin>>type;
		if(type=='!') {
			cin>>k>>x;
			k--;
			update(k+N, x);
		} else {
			cin>>a>>b;
			cout<<query(1, a, b)<<'\n';
		}
	}

	return 0;
}
