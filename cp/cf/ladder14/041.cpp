/*
https://codeforces.com/problemset/problem/510/B
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<char> > grid;
vector<vector<bool> > visited;
vector<vector<int> > dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};
int n, m;

// ( source ) -> ( destination )
// ( x0, y0 ) -> ( x1, y1 )
void dfs(int x0, int y0, int x1, int y1) {

	if(grid[x0][y0] != grid[x1][y1]) {
		return;
	}
	if(visited[x1][y1]) {
		cout<<"Yes";
		exit(0);
	}
	visited[x1][y1] = true;

	for(auto dir: dirs) {
		int x = x1+dir[0];
		int y = y1+dir[1];
		if(x<0 || x>=n || y<0 || y>=m || (y==y0 && x==x0)) {
			continue;
		}
		dfs(x1, y1, x, y);
	}
}

int main() {
	cin>>n>>m;

	grid = vector<vector<char> >(n, vector<char>(m, '.'));
	visited = vector<vector<bool> >(n, vector<bool>(m, false));

	for(int r=0; r<n; r++) {
		for(int c=0; c<m; c++) {
			cin>>grid[r][c];
		}
	}

	for(int r=0; r<n; r++) {
		for(int c=0; c<m; c++) {
			if(visited[r][c] == false) {
				dfs(r, c, r, c);
			}
		}
	}

	cout<<"No";

	return 0;

}

