/*
https://codeforces.com/problemset/problem/275/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int mat[3][3], out[3][3];
	int r, c;
	int row, col;
	int dirs[5][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}, {0,0}};

	for(r=0; r<3; r++) {
		for(c=0; c<3; c++) {
			cin>>mat[r][c];
			out[r][c] = 1;
		}
	}

	for(r=0; r<3; r++) {
		for(c=0; c<3; c++) {
			mat[r][c] %= 2;
			if(mat[r][c]) {
				for(auto dir: dirs) {
					row = r+dir[0];
					col = c+dir[1];
					if(row<0 || row>=3 || col<0 || col>=3) {
						continue;
					}
					out[row][col] = (1+out[row][col])%2;
				}
			}
		}
	}

	for(r=0; r<3; r++) {
		for(c=0; c<3; c++) {
			cout<<out[r][c];
		}
		cout<<'\n';
	}

	return 0;
}
