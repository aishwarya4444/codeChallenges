/*
https://www.codechef.com/problems/WORKCHEF

Sanyam Solution
30 points
https://www.codechef.com/viewsolution/26138061
TLE happens because dp takes lot of memory
instead of taking LCM of 2*3*2*5*7*2*3 = 2520
we so not consider 5 and take LCM = 2520/5 = 504 and 5 separately

100 points
https://www.codechef.com/viewsolution/26138340
*/


#include<bits/stdc++.h>
using namespace std;

#define ll long long

string s;
int k;
ll l, r;
ll dp[19][2][504][1<<10];

ll solve(int pos, bool tight, int mod, int mask, int last) {
    if(pos == s.size()) {
        int count = 0;
        for(int d=1; d<10; d++) {
            if(d!=5 && mask&(1<<(d-1)) && mod%d==0) {
                count++;
            }
        }
        if(mask&(1<<4) && last%5==0) {
            count++;
        }
        return count>=k;
    }

    if(dp[pos][tight][mod][mask] != -1) {
        return dp[pos][tight][mod][mask];
    }

    ll ans = 0;
    int end = tight ? s[pos]-'0' : 9;
    for(int d=0; d<=end; d++) {
        if(d) {
            ans += solve(pos+1, tight&(d==end), (mod*10+d)%504, mask|(1<<(d-1)), d);
        } else {
            ans += solve(pos+1, tight&(d==end), (mod*10)%504, mask, d);
        }
    }

    return dp[pos][tight][mod][mask] = ans;
}

int main() {
    int q;

    cin>>q;
    while(q--) {
        cin>>l>>r>>k;

        l--;
        s = to_string(l);
        memset(dp, -1, sizeof dp);
        ll res1 = solve(0, 1, 0, 0, 0);

        s = to_string(r);
        memset(dp, -1, sizeof dp);
        ll res2 = solve(0, 1, 0, 0, 0);

        cout<<res2-res1<<endl;
    }


    return 0;
}
