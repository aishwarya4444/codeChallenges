/*
https://codeforces.com/problemset/problem/275/B

BFS solution
https://codeforces.com/contest/275/submission/37847159

DFS solution
using 4 d array
https://codeforces.com/contest/275/submission/63283167
*/



#include<bits/stdc++.h>
using namespace std;

char grid[50][50];
int visited[50][50];
int dirs[4][2] = {{-1,0}, {0,1}, {1,0}, {0,-1}};

struct node {
	int row, col, dir, count;
};

struct cmp {
	bool operator()(const node &n1, const node &n2) {
		return n1.count > n2.count;
	}
};

int main()
{
	int n, m;
	int r, c, row, col, black=0, dir, count, total=0;
	priority_queue<node, vector<node>, cmp> pq;

	cin>>n>>m;

	for(r=0; r<n; r++) {
		for(c=0; c<m; c++) {
			cin>>grid[r][c];
			if(grid[r][c]=='B') {
				black++;
				if(black==1) {
					pq.push({r, c, -1, 1});
					memset(visited, 0, sizeof(visited));
				}
			}
		}
	}

	while(pq.size()) {
		auto tmp = pq.top();
		pq.pop();
		r = tmp.row;
		c = tmp.col;
		dir = tmp.dir;
		count = tmp.count;

		if(!visited[r][c]) {
			total++;
			visited[r][c] = count;
		}

		for(int d=0; d<4; d++) {
			row = r+dirs[d][0];
			col = c+dirs[d][1];
			if(row<0 || row>=n || col<0 || col>=m || grid[row][col]=='W') {
				continue;
			}
			int diff = d!=dir ? 1 : 0;
			if(count+diff>=3) {
				continue;
			}
			if(visited[row][col]>0 && count>visited[row][col]) {
				continue;
			}
			pq.push({row, col, d, count+diff});
		}
	}
	if(total==black) {
		cout<<"YES";
	} else {
		cout<<"NO";
	}

	return 0;

}
