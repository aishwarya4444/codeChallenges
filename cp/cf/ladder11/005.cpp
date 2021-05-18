/*
https://codeforces.com/problemset/problem/271/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	unordered_set<int> st, sy;
	int y, year;
	bool found = false;

	si(y);
	year = y;

	for(y=year+1; ; y++) {
		year = y;
		found = true;
		while(year) {
			if(st.count(year%10)) {
				found = false;
			}
			st.insert(year%10);
			year /= 10;
		}
		st.clear();
		if(found) {
			break;
		}
	}

	cout<<y;

	return 0;
}
