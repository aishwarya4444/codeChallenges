/*
https://leetcode.com/problems/maximal-square/
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp[1001][1001];

int main() {
    int R, C;
    int r, c, res=0;

    cin>>R>>C;

    for(r=1; r<=R; r++) {
        for(c=1; c<=C; c++) {
            cin>>dp[r][c];
            if(dp[r][c]) {
                dp[r][c] = 1+min({dp[r-1][c], dp[r-1][c-1], dp[r][c-1]});
            }
            res = max(res, dp[r][c]);
        }
    }

    cout<<res;

    return 0;
}
