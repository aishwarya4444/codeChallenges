/*
https://www.codechef.com/problems/INCXOR

Sanyam Solution
https://www.codechef.com/viewsolution/26137893
*/



#include<bits/stdc++.h>
using namespace std;

#define ll long long

int t, n;
const int mod = 1e9+7;
ll ar[5];
ll dp[32][1<<5][1<<5];

ll solve(int pos, int xtight, int btight) {
    if(pos==31) {
        return 1;
    }

    if(dp[pos][xtight][btight] != -1) {
        return dp[pos][xtight][btight];
    }

    ll ret = 0;
    int a = 0;

    for(int i=0; i<n; i++) {
        if( ar[i] & (1<<(30-pos)) ) {
            a |= (1<<i);
        }
    }

    for(int xo=0; xo<(1<<n); xo++) {
        bool flag = 1;
        int b = xo^a;
        int thisbit = 0;
        int nextbit = 0;
        int xntight = 0;
        int bntight = 0;

        for(int i=n-1; i>=0; i--) {
            thisbit = ( b & (1<<i) ) ? 1 : 0;
            if(btight & (1<<i)) {
                if(nextbit < thisbit) {
                    flag = 0;
                }
                if(nextbit == thisbit) {
                    bntight |= (1<<i);
                }
            }
            nextbit = thisbit;
        }

        for(int i=n-1; i>=0; i--) {
            thisbit = ( xo & (1<<i) ) ? 1 : 0;
            if(xtight & (1<<i)) {
                if(nextbit < thisbit) {
                    flag = 0;
                }
                if(nextbit == thisbit) {
                    xntight |= (1<<i);
                }
            }
            nextbit = thisbit;
        }

        if(flag) {
            ret += solve(pos+1, xntight, bntight);
            ret %= mod;
        }
    }

    return dp[pos][xtight][btight] = ret;
}

int main() {
    cin>>t;

    while(t--) {
        cin>>n;
        for(int i=0; i<n; i++) {
            cin>>ar[i];
        }

        memset(dp, -1, sizeof dp);
        cout<<solve(0, (1<<(n-1))-1, (1<<(n-1))-1)<<endl;
    }

    return 0;
}
