/*
https://cses.fi/problemset/task/1639
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp[5001][5001];

int main() {
    string s1, s2;

    cin>>s1>>s2;

    int n=s1.size(), m=s2.size();

    for(int r=0; r<=n; r++) {
    	dp[r][0] = r;
    }

    for(int c=1; c<=m; c++) {
    	dp[0][c] = c;
    }

    for(int r=1; r<=n; r++) {
    	for(int c=1; c<=m; c++) {
    		if(s1[r-1]==s2[c-1]) {
    			dp[r][c] = dp[r-1][c-1];
    		} else {
    			dp[r][c] = 1 + min({dp[r-1][c], dp[r-1][c-1], dp[r][c-1]});
    		}
    	}
    }

    cout<<dp[n][m];

    return 0;
}
