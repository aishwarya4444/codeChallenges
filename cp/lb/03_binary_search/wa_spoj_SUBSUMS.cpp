/*
https://www.spoj.com/problems/SUBSUMS/

https://www.youtube.com/watch?v=VCZ4lqfZRPk
https://github.com/Arjav96/My-Spoj-Solutions/blob/master/SUBSUMS.cpp
https://github.com/tr0j4n034/SPOJ/blob/master/SUBSUMS.cpp
https://github.com/codophobia/Spoj-Solutions/blob/master/SUBSUMS.cpp

N = 34 is too large
2^34 subsets are possible
processing can only be done for 10^6
2^17 is much less than 10^6
so divide in 2 sets
*/

#include <bits/stdc++.h>
using namespace std;

int N, A, B;
int s[34];

vector<int> solve(int start, int end) {
	int sum, L = end-start+1;
	vector<int> result;

	for(int mask=0; mask<(1<<L); mask++) {
		sum = 0;
		for(int j=0; j<L; j++) {
			if(mask & (1<<j)) {
				sum += s[j+start];
			}
		}
		result.push_back(sum);
	}

	return result;
}

int main() {

	int total = 0;

	cin>>N>>A>>B;

	for(int n=0; n<N; n++) {
		cin>>s[n];
	}

	vector<int> left = solve(0, N/2);
	vector<int> right = solve(N/2+1, N-1);

	sort(right.begin(), right.end());

	for(long num: left) {
		int lo = lower_bound(right.begin(), right.end(), A-num) - right.begin();
		int hi = upper_bound(right.begin(), right.end(), B-num) - right.begin();
		total += hi-lo;
	}

	cout<<total;

	return 0;
}