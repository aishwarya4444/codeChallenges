/*
https://cses.fi/problemset/task/1633
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[1000001];
const int mod = 1e9+7;

int solve(int n) {
	if(n<0) {
		return 0;
	}

	if(n==0) {
		return 1;
	}

    if(dp[n]!=-1) {
        return dp[n];
    }

    ll ans = 0;
    for(int dice=1; dice<=6; dice++) {
    	ans = (ans + solve(n-dice))%mod;
    }

    return dp[n] = ans;
}

int main() {
    int n;

    cin>>n;
    memset(dp, -1, sizeof(dp));

    cout<<solve(n);

    return 0;

}
