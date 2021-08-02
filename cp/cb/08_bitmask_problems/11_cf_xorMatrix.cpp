/*
https://codeforces.com/problemset/problem/1151/B
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
int a[501][501];
int dp[501][1<<10];
vector<int> res;

int solve(int i, int mask) {
    if(i==n) {
        return mask!=0 ? 1 : 0;
    }


    if(dp[i][mask] != -1) {
        return dp[i][mask];
    }

    bool ans = 0;

    for(int j=0; j<m; j++) {
        res.push_back(1+j);
        ans += solve(i+1, mask^a[i][j]);
        if(ans > 0) {
            ans = 1;
            break;
        } else {
            res.pop_back();
        }
    }

    return dp[i][mask] = ans;
}

int main() {
    cin>>n>>m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin>>a[i][j];
        }
    }

    memset(dp, -1, sizeof dp);
    if(solve(0, 0)) {
        cout<<"TAK\n";
        for(int num: res) {
            cout<<num<<' ';
        }
    } else {
        cout<<"NIE";
    }

    return 0;
}
