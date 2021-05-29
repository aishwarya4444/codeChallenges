/*
https://codeforces.com/problemset/problem/456/A
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a, b;
	vector<pair<int, int > > v;

	cin>>n;
	while(n--) {
		cin>>a>>b;
		v.push_back({a, b});
	}

	sort(v.begin(), v.end());

	for(n=0; n<v.size()-1; n++) {
		if(v[n].second>v[n+1].second) {
			cout<<"Happy Alex";
			return 0;
		}
	}

	cout<<"Poor Alex";

	return 0;
}