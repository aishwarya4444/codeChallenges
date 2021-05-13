/*
https://www.spoj.com/problems/SUMFOUR/

a+b+c+d = 0
a+b     = -(c+d)

https://www.cplusplus.com/reference/algorithm/equal_range/
*/

#include <bits/stdc++.h>
using namespace std;

int N;
int s[2500][4];


int main() {
	int lo, hi, total=0;
	vector<int> left, right;

	cin>>N;

	for(int n=0; n<N; n++) {
		cin>>s[n][0]>>s[n][1]>>s[n][2]>>s[n][3];
	}

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			left.push_back(s[i][0]+s[j][1]);
			right.push_back(-s[i][2]-s[j][3]);
		}
	}

	sort(right.begin(), right.end());

	for(int sum: left) {
		pair<vector<int>::iterator, vector<int>::iterator > bound;
		bound = equal_range(right.begin(), right.end(), sum);
		// below 2 lines used binary search twice
		// this lead to TLE
		// lo = lower_bound(right.begin(), right.end(), sum)-right.begin();
		// hi = upper_bound(right.begin(), right.end(), sum)-right.begin();
		lo = bound.first - right.begin();
		hi = bound.second - right.begin();
		total += hi-lo;
	}

	cout<<total;

	return 0;
}
