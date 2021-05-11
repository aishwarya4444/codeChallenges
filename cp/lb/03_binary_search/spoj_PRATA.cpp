/*
https://www.spoj.com/problems/PRATA/
*/

#include <bits/stdc++.h>
using namespace std;

int P, L, T;
int maxR;
vector<int> cooks;

int getParatas(int rank, int t) {
	int time = 0;
	int parata = 0;
	while(true) {
		parata++;
		time += parata*rank;
		if(time > t) {
			parata--;
			break;
		}
	}
	return parata;
}

bool check(int t) {
	int total = 0;
	int parata;

	for(int cook: cooks) {
		parata = getParatas(cook, t);
		total += parata;
		if(total >= P) {
			return true;
		}
	}

	return false;
}

void binarySearch() {
	int start, mid, end;
	int res = -1;

	start = 0;
	end = ((P)*(P+1)/2)*maxR;
	while(start<=end) {
		mid = (end-start)/2+start;
		if(check(mid)) {
			res = mid;
			end = mid-1;
		} else {
			start = mid+1;
		}
	}

	cout<<res<<endl;
}

void readInput() {
	int cook;

	cin>>P>>L;

	maxR = 0;
	cooks.clear();
	for(int n=0; n<L; n++) {
		cin>>cook;
		cooks.push_back(cook);
		maxR = max(maxR, cook);
	}
}

int main() {

	cin >> T;

	while(T--) {
		readInput();
		binarySearch();
	}

	return 0;
}
