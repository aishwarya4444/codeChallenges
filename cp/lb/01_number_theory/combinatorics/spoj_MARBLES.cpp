/*
https://www.spoj.com/problems/MARBLES/
http://myspojsolution.blogspot.com/2017/07/spoj-marbles-solution.html
*/

#include<bits/stdc++.h>
using namespace std;

void solve(long n, long r) {
	// n C r = n C (n-r)
	if(r > n-r) {
		r = n-r;
	}

	unsigned long long res = 1;

	// Calculate value of
    // [n * (n-1) *---* (n-r+1)] / [1 * 2 *----* (r-1) * r]
    for(long i=0; i<r; i++) {
		res *= (n-i);
		res /= (i+1);
	}

	cout<<res<<endl;
}
int main()
{
	long T, N, K;

	cin>>T;
	while(T--) {
		cin>>N>>K;
		solve(N-1, K-1);
	}

	return 0;
}
