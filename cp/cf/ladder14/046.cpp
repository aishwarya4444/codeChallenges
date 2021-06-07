/*
https://codeforces.com/problemset/problem/220/A
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int n;
	vector<pair<int, int> > res;

	cin>>n;

	int a[n];
	int b[n];

	for(int i=0; i<n; i++) {
		cin>>a[i];
		b[i] = a[i];
	}

	sort(b, b+n);

	for(int i=0; i<n; i++) {
		if(a[i]!=b[i]) {
			res.push_back({a[i], b[i]});
			if(res.size()>2) {
				break;
			}
		}
	}

	if(res.size()==1 || res.size()>2) {
		cout<<"NO";
	} else {
		if(res.size()==0) {
			cout<<"YES";
			exit(0);
		}
		auto d1 = res[0];
		auto d2 = res[1];
		if(d1.first==d2.second && d1.second==d2.first) {
			cout<<"YES";
		} else {
			cout<<"NO";
		}
	}

	return 0;
}
