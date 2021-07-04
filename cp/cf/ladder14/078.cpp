/*
https://codeforces.com/problemset/problem/467/C

https://codeforces.com/contest/467/submission/88075803
https://codeforces.com/contest/467/submission/51142811
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n; // number of integers
int m; // size of each range
int k; // number of ranges
ll p[5001];
ll prefix[5001];

int main() {

    cin>>n>>m>>k;

    for(int i=1; i<=n; i++) {
    	cin>>p[i];
    	prefix[i] = prefix[i-1]+p[i];
    }

    ll dp[n+1][k+1];

    memset(dp, 0, sizeof(dp));

    for(int i=m; i<=n; i++) {
    	for(int j=1; j<=k; j++) {
    		if(j*m>i) {
    			continue;
    		}
    		dp[i][j] = max(dp[i-1][j], dp[i-m][j-1]+prefix[i]-prefix[i-m]);
    	}
    }

    cout<<dp[n][k];

    return 0;
}
