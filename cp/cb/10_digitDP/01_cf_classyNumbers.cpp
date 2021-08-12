/*
https://codeforces.com/problemset/problem/1036/C
https://codeforces.com/blog/entry/61727

Sanyam Solution
https://codeforces.com/contest/1036/submission/58461450
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll l, r;
int dp[20][4][2];
string s;

int solve(int pos, int cnt, int tight) {
    if(pos==s.size()) {
        return 1;
    }

    if(dp[pos][cnt][tight] != -1) {
        return dp[pos][cnt][tight];
    }

    int ans = 0;
    int end = tight ? (s[pos]-'0') : 9;

    for (int i = 0; i <= end; i ++){
        ll cntupd = cnt + (i>0);
        if ( cntupd > 3 )  continue;
        if (tight) {
            ans += solve(pos+1, cntupd, i==end);
        } else {
            ans += solve(pos+1, cntupd, 0);
        }
    }

    return dp[pos][cnt][tight] = ans;
}

int main() {
    int t;
    int resL, resR;
    cin>>t;

    while(t--) {
        cin>>l>>r;

        l--;
        memset(dp, -1, sizeof dp);
        s = to_string(l);
        resL = solve(0, 0, 1);

        memset(dp, -1, sizeof dp);
        s = to_string(r);
        resR = solve(0, 0, 1);

        cout<<resR-resL<<endl;

    }

    return 0;
}
