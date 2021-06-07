/*
https://codeforces.com/problemset/problem/224/B
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
	int n, k, lo=-2, hi=-2;
	vector<int> a;
	unordered_set<int> st;

	cin>>n>>k;
	a.assign(n, 0);

	for(int &num: a) {
		cin>>num;
	}

	for(int i=0; i<n; i++) {
		st.insert(a[i]);
		if(st.size()==k) {
			hi = i;
			st.clear();
			break;
		}
	}

	for(int i=hi; i>=0; i--) {
		st.insert(a[i]);
		if(st.size()==k) {
			lo=i;
			break;
		}
	}

	cout<<lo+1<<' '<<hi+1;

	return 0;
}
