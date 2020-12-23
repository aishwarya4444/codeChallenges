/*
https://www.spoj.com/problems/KGSS/
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
	int maxVal, maxSum;

	void assignLeaf(int val) {
		maxVal = val;
		maxSum = 0;
	}

	void merge(node &left, node &right) {
		maxVal = max(left.maxVal, right.maxVal);
		maxSum = max({left.maxSum, right.maxSum, left.maxVal + right.maxVal});
	}

	int getMax() {
		return maxSum;
	}
};

const int MAX = 1<<17;
node st[2*MAX+1];
int a[MAX+1];

void buildTree(int index, int l, int r) {
	if(l==r) {
		st[index].assignLeaf(a[l]);
		return;
	}

	int left = 2*index, right = 2*index+1, mid = l+(r-l)/2;

	buildTree(left, l, mid);
	buildTree(right, mid+1, r);
	st[index].merge(st[left], st[right]);
}

node queryTree(int index, int rangeStart, int rangeEnd, int l, int r) {
	if(l==rangeStart && r==rangeEnd) {
		return st[index];
	}

	int left = 2*index, right = 2*index+1, mid = l+(r-l)/2;

	if(rangeEnd <= mid) {
		return queryTree(left, rangeStart, rangeEnd, l, mid);
	}

	if(rangeStart > mid) {
		return queryTree(right, rangeStart, rangeEnd, mid+1, r);
	}

	node result,
		leftResult = queryTree(left, rangeStart, mid, l, mid),
		rightResult = queryTree(right, mid+1, rangeEnd, mid+1, r);

	result.merge(leftResult, rightResult);
	return result;
}

void getResult(int index, int rangeStart, int rangeEnd, int l, int r) {
	node result = queryTree(index, rangeStart, rangeEnd, l, r);
	cout<<result.getMax()<<endl;
}

void update(int index, int id, int val, int l, int r) {
	if(l==r) {
		st[index].assignLeaf(val);
		return;
	}

	int left = 2*index, right = 2*index+1, mid = l+(r-l)/2;

	if(id<=mid) {
		update(left, id, val, l, mid);
	} else {
		update(right, id, val, mid+1, r);
	}

	st[index].merge(st[left], st[right]);
}

int main() {
	char op;
	int x, y, n, N, Q;

	cin>>N;

	for(n=1; n<=N; n++) {
		cin>>a[n];
	}

	buildTree(1, 1, N);

	cin>>Q;

	while(Q--) {
		cin>>op>>x>>y;
		if(op=='U') {
			update(1, x, y, 1, N);
		} else {
			getResult(1, x, y, 1, N);
		}
	}

	return 0;
}