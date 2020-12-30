/*
https://www.spoj.com/problems/ROBOTGRI/
*/

#include <bits/stdc++.h>
using namespace std;

// #define MOD ((long long 1)<<31-1)

long long MOD = pow(2,31) - 1;
bool grid[1001][1001], canReach;
long long dp[1001][1001];
int n;

void dp_2dirs() {
	int r, c;

	dp[1][1] = 1;
	canReach = false;
	for(r=2; r<=n; r++) {
		if(grid[r][1]) {
			dp[r][1] = dp[r-1][1];
		} else {
			dp[r][1] = 0;
		}
	}

	for(c=2; c<=n; c++) {
		if(grid[1][c]) {
			dp[1][c] = dp[1][c-1];
		} else {
			dp[1][c] = 0;
		}
	}

	for(r=2; r<=n; r++) {
		for(c=2; c<=n; c++) {
			if(grid[r][c]) {
				dp[r][c] = dp[r-1][c] + dp[r][c-1];
				/* handle case for MOD % MOD */
				canReach = r==n && c==n && dp[r][c]>0;
				dp[r][c] %= MOD;
			} else {
				dp[r][c] = 0;
			}
		}
	}
}

bool check_alldirs() {
	queue<pair<int, int> > q;
	int row, col, r, c;
	vector<vector<int> > dirs = {{-1,0}, {0,1}, {1,0}, {0,-1}};

	q.push({0, 0});
	while(q.size()) {
		auto node = q.front();
		q.pop();

		row = node.first;
		col = node.second;
		if(grid[row][col] == false) {
			continue;
		}
		grid[row][col] = false;

		for(auto dir: dirs) {
			r = row+dir[0];
			c = col+dir[1];
			if(r>=1 && r<=n && c>=1 && c<=n && grid[r][c]) {
				if(r==n && c==n) {
					return true;
				}
				q.push({r, c});
			}
		}
	}

	return false;
}

void solve() {

	dp_2dirs();
	if(dp[n][n]) {
		cout<<dp[n][n]<<endl;
		return;
	}

	if(check_alldirs()) {
		cout<<"THE GAME IS A LIE\n";
	} else {
		cout<<"INCONCEIVABLE\n";
	}

}

int main() {
	int r, c;
	char ch;

	cin>>n;

	for(r=1; r<=n; r++) {
		for(c=1; c<=n; c++) {
			cin>>ch;
			grid[r][c] = ch=='.' ? true : false;
		}
	}

	solve();

	return 0;
}
