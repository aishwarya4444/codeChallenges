/*
https://www.spoj.com/problems/BRCKTS/
https://kartikkukreja.wordpress.com/2014/11/09/a-simple-approach-to-segment-trees/
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
	int open, close;

	void assignLeaf(char bracket) {
		if(bracket == '(') {
			open = 1;
			close = 0;
		} else {
			open = 0;
			close = 1;
		}
	}

	void merge(node &left, node &right) {
		open = right.open;
		close = left.close;

		if(left.open > right.close) {
			open += left.open-right.close;
		}

		if(left.open < right.close) {
			close += right.close-left.open;
		}
	}

	int getTotal() {
		return open+close;
	}
};

const int MAX = 1<<15;
node st[2*MAX+1];
string a;

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


void getResult() {
	int unmatchedCount = st[1].getTotal();

	if(unmatchedCount == 0) {
		cout<<"YES\n";
	} else {
		cout<<"NO\n";
	}
}

void update(int index, int id, int l, int r) {
	if(l==r) {
		a[id] = a[id]=='(' ? ')' : '(';
		st[index].assignLeaf(a[id]);
		return;
	}

	int left = 2*index, right = 2*index+1, mid = l+(r-l)/2;

	if(id<=mid) {
		update(left, id, l, mid);
	} else {
		update(right, id, mid+1, r);
	}

	st[index].merge(st[left], st[right]);
}

int main() {
	int op, id, N, m, k, test;

	for(test = 1; test <= 10; test++) {
		cin>>N>>a>>m;
		a = " "+a;
		buildTree(1, 1, N);
		cout<<"Test "<<test<<":\n";
		while(m--) {
			cin>>k;
			if(k==0) {
				getResult();
			} else {
				update(1, k, 1, N);
			}
		}
	}

	return 0;
}