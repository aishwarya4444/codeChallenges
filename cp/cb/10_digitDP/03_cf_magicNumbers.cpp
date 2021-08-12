/*
https://codeforces.com/problemset/problem/628/D

Sanyam Solution
https://codeforces.com/contest/628/submission/58461179
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

string s, a, b;
int d, m;
ll dp[2005][2005][2][2][2];
const int mod = 1e9+7;

ll solve(int pos, int mo, bool tight, bool start, bool even) {
    if(pos == s.size()) {
        return mo==0;
    }

    if(dp[pos][mo][tight][start][even] != -1) {
        return dp[pos][mo][tight][start][even];
    }

    ll ans = 0;
    int end = tight ? s[pos]-'0' : 9;

    if(start) {
        for(int i=0; i<=end; i++) {
            if(even && (i==d)) {
                ans = (ans + solve(pos+1, (mo*10+i)%m, tight&(i==end), 1, !even)) % mod;
            } else if( (!even) && (i!=d)) {
                ans = (ans + solve(pos+1, (mo*10+i)%m, tight&(i==end), 1, !even)) % mod;
            }
        }
    } else {
        ans = solve(pos+1, mo, tight&(s[pos]=='0'), start, 0) % mod;
        for(int i=0; i<=end; i++) {
            if(i!=d) {
                ans = (ans + solve(pos+1, (mo*10+i)%m, tight&(i==end), 1, 1)) % mod;
            }
        }
    }

    return dp[pos][mo][tight][start][even] = ans;
}

int main() {
    cin>>m>>d;
    cin>>a>>b;

    s = b;
    memset(dp, -1, sizeof dp);
    ll ans = solve(0, 0, 1, 0, 0);

    s = a;
    memset(dp, -1, sizeof dp);
    ans = (ans - solve(0, 0, 1, 0, 0) + mod) % mod;

    // numbers a and b can be very large .. upto 2000 digits
    // so to print answer = f(b) - f(a-1) .. we need to do a-- which is extra task
    // alternative way is = f(b) - f(a) + isMagic(a)
    ll mo = 0;
    bool flag = 1;
    for(int i=0; i<a.size(); i++) {
        if(i%2 && ((a[i]-'0')!=d)) {
            flag = 0;
        }
        if(i%2==0 && ((a[i]-'0')==d)) {
            flag = 0;
        }
        mo = (mo*10 + (a[i]-'0')) % m;
    }
    if(mo==0 && flag) {
        ans = (ans + 1) % mod;
    }

    cout<<ans;

    return 0;
}
