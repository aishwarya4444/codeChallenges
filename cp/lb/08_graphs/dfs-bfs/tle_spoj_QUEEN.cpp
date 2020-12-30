/*
https://www.spoj.com/problems/QUEEN/
http://zobayer.blogspot.com/2013/12/spoj-queen.html
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<bool> > g;
vector<vector<int> > dirs = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}};
int R, C, srcRow, srcCol, desRow, desCol;
struct node {
	int row, col, level;
	node(int r, int c, int l) {
		row = r;
		col = c;
		level = l;
	}
};

bool canMove(int r, int c) {
	if(r>=0 && r<R && c>=0 && c<C && g[r][c]) {
		return true;
	} else {
		return false;
	}
}

void bfs() {
	queue<node> q;
	int row, col, level, r, c;

	q.push({srcRow, srcCol, 0});
	while(q.size()) {
		auto qnode = q.front();
		q.pop();

		row = qnode.row;
		col = qnode.col;
		level = qnode.level;

		g[row][col] = false;

		if(row == desRow && col == desCol) {
			cout<<level<<'\n';
			return;
		}

		for(auto dir: dirs) {
			r = row+dir[0];
			c = col+dir[1];

			if(canMove(r, c)) {
				while(canMove(r, c)) {
					r = r+dir[0];
					c = c+dir[1];
				}
				q.push({r-dir[0], c-dir[1], 1+level});
			}
		}

	}

	cout<<"-1\n";
	return;
}

int main() {
	int r, c, n, m, t;
	char chr;

	cin>>t;
	while(t--) {
		cin>>n>>m;
		R = n;
		C = m;

		g = vector<vector<bool> >(R, vector<bool>(C, true));
		for(r=0; r<R; r++) {
			for(c=0; c<C; c++) {
				cin>>chr;
				if(chr=='X') {
					g[r][c] = false;
				} else if(chr=='S') {
					srcRow = r;
					srcCol = c;
					g[r][c] = false;
				} else if(chr=='F') {
					desRow = r;
					desCol = c;
				}
			}
		}

		bfs();
	}
	return 0;
}
