/*
https://cses.fi/problemset/task/1634
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[1000001];
const int INF = 1e9;
vector<int> coins;

int solve(int x) {
	if(x==0) {
		return 0;
	}

    if(dp[x]!=-1) {
        return dp[x];
    }

    int ans = INF;
    for(int &coin: coins) {
    	if(x<coin) continue;
    	ans = min(ans, 1+solve(x-coin));
    }

    return dp[x] = ans;
}

int main() {
    int n, x;

    cin>>n>>x;
    memset(dp, -1, sizeof(dp));
    coins.resize(n);

    for(int i=0; i<n; i++) {
    	cin>>coins[i];
    }

    int ans = solve(x);

    ans = ans>=INF ? -1 : ans;

    cout<<ans;

    return 0;
}
