/*
https://www.spoj.com/problems/KFSTB/

    # dfs
    # dp
    # realise that it is DAG
    # The commander also knows that if the army leaves a camping spot along a bridge safely it is not possible to return back safely to the same camping spot.

*/

// accepted
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int C, B, S, T;
unordered_map<int, vector<int> > g;
vector<int> dp;

int dfs(int u) {
	if(u == T) {
		return 1;
	}

	if(dp[u] != -1) {
		return dp[u];
	}

	long total = 0;
	for(int v: g[u]) {
		total = (total + dfs(v))%MOD;
	}
	dp[u] = total;
	return dp[u];
}

int main() {
	int D, X, Y;

	cin>>D;
	while(D--) {
		cin>>C>>B>>S>>T;

		g.clear();
		dp = vector<int>(C+1, -1);

		while(B--) {
			cin>>X>>Y;
			g[X].push_back(Y);
		}

		dfs(S);

		cout<<dp[S]<<endl;
	}

	return 0;
}


// tle
#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

unordered_map<int, vector<int> > g;
int C, B, S, T;
long long total;
vector<bool> visited;

void dfs(int u) {
	if(u == T) {
		total = (1+total)%MOD;
		return;
	}

	if(visited[u]) {
		return;
	}

	visited[u] = true;
	for(int v: g[u]) {
		dfs(v);
	}
	visited[u] = false;
}

int main() {
	int D, X, Y;

	cin>>D;
	while(D--) {
		total = 0;
		cin>>C>>B>>S>>T;

		g.clear();
		visited = vector<bool>(C+1, false);

		while(B--) {
			cin>>X>>Y;
			g[X].push_back(Y);
		}

		dfs(S);

		cout<<total<<endl;
	}

	return 0;
}
