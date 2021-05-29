/*
https://codeforces.com/problemset/problem/349/A

The solution is to keep track of the number of 25 and 50 ruble bills.
Act greedily when giving change to 100 rubles — try 25+50 first and then 25+25+25.
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int n, val;
	unordered_map<int, int> m;

	si(n);

	while(n--) {
		si(val);
		if(val == 25) {
			m[25]++;
		} else if(val == 50) {
			if(m[25]) {
				m[25]--;
			} else {
				cout<<"NO";
				return 0;
			}
			m[50]++;
		} else {
			if(m[50]) {
				m[50]--;
				if(m[25]) {
					m[25]--;
				} else {
					cout<<"NO";
					return 0;
				}
				m[100]++;
			} else {
				if(m[25]>=3) {
					m[25]-=3;
				} else {
					cout<<"NO";
					return 0;
				}
				m[100]++;
			}
		}
	}

	cout<<"YES";

	return 0;
}
