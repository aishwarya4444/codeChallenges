/*
https://www.codechef.com/problems/CD1IT4
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int m, n, p;
// grid
ll a[1001][1001];
const int mod = 1e9+7;

int main() {
    int r, c;

    cin>>m>>n>>p;

    while(p--) {
        cin>>r>>c;
        a[r][c] = 1;
    }

    if(a[1][1]) {
        cout<<0;
        return 0;
    }

    a[1][1] = 1;

    for(r=1, c=2; c<=n; c++) {
        if(a[r][c]) {
            a[r][c] = 0;
        } else {
            a[r][c] = a[r][c-1];
        }
    }

    for(r=2, c=1; r<=m; r++) {
        if(a[r][c]) {
            a[r][c] = 0;
        } else {
            a[r][c] = a[r-1][c];
        }
    }

    for(r=2; r<=m; r++) {
        for(c=2; c<=n; c++) {
            if(a[r][c]) {
                a[r][c] = 0;
            } else {
                a[r][c] = (a[r][c-1]+a[r-1][c])%mod;
            }
        }
    }

    cout<<a[m][n];

    return 0;
}
