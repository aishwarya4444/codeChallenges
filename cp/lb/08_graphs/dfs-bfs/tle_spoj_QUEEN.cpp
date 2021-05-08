/*
https://www.spoj.com/problems/QUEEN/

https://www.spoj.com/problems/MLASERP/

https://www.quora.com/How-does-bit-manipulation-in-the-SPOJ-QUEEN-problem-work
http://zobayer.blogspot.com/2013/12/spoj-queen.html
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
using namespace std;

vector<vector<int> > g;
vector<vector<int> > dirs = {{0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}, {-1,0}, {-1,1}};
int R, C, srcRow, srcCol, desRow, desCol;
int cellFreeMask = 0;
int cellBlockMask = 255;

struct node {
	int row, col, level;
	node(int r, int c, int l) {
		row = r;
		col = c;
		level = l;
	}
};

bool canMove(int r, int c, int dir) {
	return r>=0 && r<R && c>=0 && c<C && g[r][c]!=cellBlockMask;
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

		if(row == desRow && col == desCol) {
			printf("%d\n", level);
			return;
		}

		for(int d=0; d<8; d++) {
			r = row;
			c = col;

			while((g[r][c] ^ (1<<d)) && canMove(r+dirs[d][0], c+dirs[d][1], d)) {
				g[r][c] = g[r][c] | (1<<d);
				r = r+dirs[d][0];
				c = c+dirs[d][1];
				q.push({r, c, 1+level});
			}
		}

	}

	printf("-1\n");
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int r, c, n, m, t;
	char chr;

	// si(t);
	cin>>t;
	while(t--) {
		cin>>n>>m;
		// si(n);
		// si(m);
		R = n;
		C = m;

		g = vector<vector<int> >(R, vector<int>(C, cellFreeMask));
		for(r=0; r<R; r++) {
			for(c=0; c<C; c++) {
				cin>>chr;
				if(chr=='X') {
					g[r][c] = cellBlockMask;
				} else if(chr=='S') {
					srcRow = r;
					srcCol = c;
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
