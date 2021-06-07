/*
https://codeforces.com/problemset/problem/257/C
*/

#include<bits/stdc++.h>
using namespace std;

#define ld long double

const ld pi = 4*atan(1.0);

int main()
{
	int n;
	vector<ld> m;
	ld x, y;

	cin>>n;

	for(int i=0; i<n; i++) {
		cin>>x>>y;
		m.push_back(atan2(y,x)*180.0/pi);
	}

	sort(m.begin(), m.end());

	ld res = m.back()-m[0];

	for(int i=1; i<n; i++) {
		res = min(res, 360 - (m[i]-m[i-1]));
	}

	cout.precision(10);
	cout<<res;

	return 0;

}
