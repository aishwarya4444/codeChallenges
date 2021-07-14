/*
https://codeforces.com/problemset/problem/1169/E

Sanyam Solution
https://codeforces.com/problemset/submission/1169/59820781

Codeforces Editorial
https://pastebin.com/QbQa3x4V
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll a[300010];
ll dist1to1[25][25];
ll minDist[300010][25];
ll n, q, x, y;

int main() {
    cin>>n>>q;
    for(ll i=1; i<=n; i++) {
        cin>>a[i];
    }

    for(ll i=0; i<=20; i++) {
        for(ll j=0; j<=20; j++) {
            if(i != j) {
                dist1to1[i][j] = INT_MAX;
            }
        }
    }

    for(ll i=n; i>=1; i--) {
        vector<ll> zeros, ones;
        for(ll j=0; j<=20; j++) {
            if( (1<<j)&a[i] ) {
                minDist[i][j] = 0;
                ones.push_back(j);
                for(int k=0; k<=20; k++) {
                    if( (1<<k)&a[i] ) {
                        dist1to1[j][k] = 0;
                    }
                }
            } else {
                zeros.push_back(j);
            }
        }

        for(auto it0: zeros) {
            ll mi = INT_MAX;
            for(auto it1: ones) {
                mi = min(mi, dist1to1[it1][it0]);
            }
            for(auto it1: ones) {
                dist1to1[it1][it0] = mi;
            }
            // because we can jump from any set bit in the number
            // to any set bit in the same number in 0 steps
            minDist[i][it0] = mi;
        }

        for(ll j=0; j<=20; j++) {
            for(ll k=0; k<=20; k++) {
                if(j != k) {
                    dist1to1[j][k]++;
                }
            }
        }

    }

    while(q--) {
        cin>>x>>y;
        ll mi = INT_MAX;
        for(ll j=0; j<=20; j++) {
            if(a[y]&(1<<j)) {
                mi = min(mi, minDist[x][j]);
            }
        }
        if(mi <= y-x) {
            cout<<"Shi\n";
        } else {
            cout<<"Fou\n";
        }
    }

    return 0;
}
