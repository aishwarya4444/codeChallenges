/*
https://www.spoj.com/problems/PIE/
*/

#include <bits/stdc++.h>
using namespace std;

#define PI acos(-1.0)
#define EPSILON 1e-6
// WA for 1e-3

int T, N, F;
double r[10000];

bool check(double limit) {
	int count = 0;
	double volume;

	for(int n=0; n<N; n++) {
		volume = PI*r[n]*r[n];
		count += (int) floor(volume/limit);
	}

	return count >= F+1;
}

int main() {

	double start, mid, end, result;

	cin>>T;
	while(T--) {
		cin>>N>>F;

		start = 0.0;
		end = 0.0;

		for(int n=0; n<N; n++) {
			cin>>r[n];
			end = max(end, PI*r[n]*r[n]);
		}

		while(start <= end) {
			mid = (end+start)/2.0;
			if(check(mid)) {
				result = mid;
				start = mid+EPSILON;
			} else {
				end = mid-EPSILON;
			}
		}

		printf("%.4lf\n", result);

	}

	return 0;
}
