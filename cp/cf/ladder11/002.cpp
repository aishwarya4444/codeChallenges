/*
https://codeforces.com/problemset/problem/263/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int r, c, row, col;
	int val, N=5;
	bool mat[5][5];

	for(r=0; r<N; r++) {
		for(c=0; c<N; c++) {
			si(val);
			if(val==1) {
				row = r;
				col = c;
				mat[r][c] = true;
			} else {
				mat[r][c] = false;
			}
		}
	}

	cout<<abs(2-row)+abs(2-col);

	return 0;
}
