/*
https://www.spoj.com/problems/LABYR1/

        # diameter of tree
        # bfs twice
*/

#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<vector<bool> > g, visited;
vector<vector<int> > dirs = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct result {
	int row, col, len;
	result(int r, int c, int l) {
		row = r;
		col = c;
		len = l;
	}
};

bool insideGraph(int r, int c) {
	if(r>=1 && r<=R && c>=1 && c<=C) {
		return true;
	}
	return false;
}

result bfs(int r, int c) {
	queue<pair<int, int> > q;
	int row, col, level=0, N;

	visited = g;
	q.push({r, c});
	while(q.size()) {
		N = q.size();
		level++;
		while(N--) {
			r = q.front().first;
			c = q.front().second;
			q.pop();
			visited[r][c] = false;
			for(auto dir: dirs) {
				row = r+dir[0];
				col = c+dir[1];
				if(insideGraph(row, col) && visited[row][col]) {
					q.push({row, col});
				}
			}
		}
	}

	return {r, c, level};
}

int main() {
	int r, c, row, col, T;
	char block;

	cin>>T;
	while(T--) {
		cin>>C>>R;
		g = vector<vector<bool> >(R+1, vector<bool>(C+1, false));

		for(r=1; r<=R; r++) {
			for(c=1; c<=C; c++) {
				cin>>block;
				if(block=='.') {
					g[r][c] = true;
					row = r;
					col = c;
				}
			}
		}

		auto bfsResult = bfs(row, col);
		bfsResult = bfs(bfsResult.row, bfsResult.col);
		cout<<"Maximum rope length is "<<bfsResult.len-1<<".\n";
	}

	return 0;
}
