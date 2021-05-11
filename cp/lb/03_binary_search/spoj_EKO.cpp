/*
https://www.spoj.com/problems/EKO/
*/

#include <bits/stdc++.h>
using namespace std;

int N, M, maxH;
vector<int> trees;

bool check(int limit) {
	int total = 0;

	for(int tree: trees) {
		if(tree<=limit) {
			continue;
		}
		total += tree-limit;
		if(total >= M) {
			return true;
		}
	}

	return false;
}

void binarySearch() {
	int start = 0, mid, end = maxH;
	int H = -1;

	while(start<=end) {
		mid = (end-start)/2+start;
		if(check(mid)) {
			H = mid;
			start = mid+1;
		} else {
			end = mid-1;
		}
	}

	cout<<H<<endl;
}

void readInput() {
	int tree;

	cin>>N>>M;

	maxH = 0;

	for(int n=0; n<N; n++) {
		cin>>tree;
		trees.push_back(tree);
		maxH = max(maxH, tree);
	}
}

int main() {

	readInput();
	binarySearch();

	return 0;
}
