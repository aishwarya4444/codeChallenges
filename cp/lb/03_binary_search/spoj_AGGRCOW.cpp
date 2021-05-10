/*
https://www.spoj.com/problems/AGGRCOW/

https://www.youtube.com/watch?v=fjcpZbEDslE
https://www.youtube.com/watch?v=TC6snf6KPdE
https://www.youtube.com/watch?v=SiE1XFhYoaA
*/

#include <bits/stdc++.h>
using namespace std;

int N, C, T;
vector<int> stall;

bool check(int limit) {
	int cows = 0;
	int prev = -stall.back();

	for(int dist: stall) {
		if(dist-prev >= limit) {
			prev = dist;
			cows++;
		}
	}

	return cows >= C;
}

void binarySearch() {
	int start, mid, end;
	int result = -1;

	sort(stall.begin(), stall.end());
	start = 0;
	end = stall.back()-stall.front();

	while(start<=end) {
		mid = (end-start)/2+start;
		if(check(mid)) {
			result = mid;
			start = mid+1;
		} else {
			end = mid-1;
		}
	}

	cout<<result<<endl;
}

void readInput() {
	int dist;

	cin>>N>>C;

	stall.clear();
	for(int n=0; n<N; n++) {
		cin>>dist;
		stall.push_back(dist);
	}
}

int main() {

	cin>>T;
	while(T--) {
		readInput();
		binarySearch();
	}

	return 0;
}
