/*
https://codeforces.com/problemset/problem/377/A
*/

#include<bits/stdc++.h>
using namespace std;

char grid[500][500];
bool visited[500][500];
int dir[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int n, m, k, empty=0;

void dfs(int row, int col, int &visit) {
	if(visit+k == empty) {
		return;
	}

	visited[row][col] = true;
	visit++;

	for(int d=0; d<4; d++) {
		int r = row+dir[d][0];
		int c = col+dir[d][1];
		if(r<0 || r>=n || c<0 || c>=m || visited[r][c]) {
			continue;
		}
		dfs(r, c, visit);
	}
}

int main()
{
	int r, c, row, col, visit=0;

	cin>>n>>m>>k;

	for(r=0; r<n; r++) {
		for(c=0; c<m; c++) {
			cin>>grid[r][c];
			if(grid[r][c]=='.') {
				empty++;
				if(empty == 1) {
					row = r;
					col = c;
				}
			} else {
				visited[r][c] = true;
			}
		}
	}

	dfs(row, col, visit);

	for(r=0; r<n; r++) {
		for(c=0; c<m; c++) {
			if(visited[r][c] == false) {
				cout<<'X';
			} else {
				cout<<grid[r][c];
			}
		}
		cout<<endl;
	}

	return 0;

}
