/*
https://cses.fi/problemset/task/1635
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[1000001];
const int INF = 1e9;
const int mod = 1e9+7;
vector<int> coins;

int solve(int x) {
	if(x<0) {
		return 0;
	}

	if(x==0) {
		return 1;
	}

    if(dp[x]!=-1) {
        return dp[x];
    }

    ll ans = 0;
    for(int &coin: coins) {
    	ans = (ans + solve(x-coin)) % mod;
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
