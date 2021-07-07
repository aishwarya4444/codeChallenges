/*
https://www.spoj.com/problems/TOURIST/
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
// grid
char a[101][101];
int dp[101][101][101];

int dx1[] = {1, 1, 0, 0};
int dy1[] = {0, 0, 1, 1};
int dx2[] = {0, 1, 0, 1};
int dy2[] = {1, 0, 1, 0};

// we take 4 states x1,y1,x2,y2
// dp has only 3 states
// because at any time x1+y1=x2+y2
// so y2 is not needed to be tracked
int solve(int x1, int y1, int x2, int y2) {
    if(x1>n || x2>n || y1>m || y2>m || a[x1][y1]=='#' || a[x2][y2]=='#') {
        return -1;
    }
    if(x1==n && y1==m) {
        return a[x1][y1]=='*';
    }
    if(dp[x1][y1][x2]!=-1) {
        return dp[x1][y1][x2];
    }

    int ans = 0;
    for(int i=0; i<4; i++) {
        ans = max( ans, solve(x1+dx1[i], y1+dy1[i], x2+dx2[i], y2+dy2[i]) );
    }

    if(a[x1][y1]=='*') {
        ans++;
    }
    if(a[x2][y2]=='*') {
        ans++;
    }
    if(x1==x2 && y1==y2 && a[x1][y1]=='*') {
        ans--;
    }

    return dp[x1][y1][x2] = ans;
}

int main() {
    int t, r, c;

    cin>>t;
    while(t--) {
        cin>>m>>n;
        memset(dp, -1, sizeof dp);

        for(r=1; r<=n; r++) {
            for(c=1; c<=m; c++) {
                cin>>a[r][c];
            }
        }

        cout<<solve(1,1,1,1)<<endl;
    }

    return 0;
}
