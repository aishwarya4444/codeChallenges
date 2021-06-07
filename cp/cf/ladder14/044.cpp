/*
https://codeforces.com/problemset/problem/279/C
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[100001];
int increase[100001];
int decrease[100001];

int main() {
	int n, m, l, r;

	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		increase[i] = i;
		decrease[i] = i;
	}

	for(int i=n-1; i>0; i--) {
		if(a[i-1]<=a[i]) {
			increase[i-1] = increase[i];
		}
	}

	for(int i=1; i<n; i++) {
		if(a[i-1]>=a[i]) {
			decrease[i] = decrease[i-1];
		}
	}

	while(m--) {
		cin>>l>>r;
		l--;
		r--;
		if(increase[l]>=decrease[r]) {
			cout<<"Yes\n";
		} else {
			cout<<"No\n";
		}
	}


	return 0;
}
