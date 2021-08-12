/*
https://codeforces.com/problemset/gymProblem/100886/G

Sanyam Solution
https://codeforces.com/gym/100886/submission/58173764
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

string a, b;
pair<ll, string> dp[20][2][2][2];

pair<ll, string> solve(int pos, int ta, int tb, int st) {
    if(pos==a.size()) {
        return {1, ""};
    }

    if(dp[pos][ta][tb][st].first != -1) {
        return dp[pos][ta][tb][st];
    }

    string ans = "";
    ll ret = -1;
    int lb = ta ? (a[pos]-'0') : 0;
    int ub = tb ? (b[pos]-'0') : 9;

    for (int i=lb; i<=ub; i++) {
        ll val = i;
        if(st==0 && i==0) {
            val = 1;
        }
        pair<ll, string> dpans = solve(pos+1, ta&(i==lb), tb&(i==ub), st|(i>0));
        if(val*dpans.first > ret) {
            ret = val*dpans.first;
            ans = dpans.second;
            if(st==0 && i==0) continue;
            ans.insert(ans.begin(), '0'+i);
        }
    }

    return dp[pos][ta][tb][st] = {ret, ans};
}

int main() {
    cin>>a>>b;

    for(int i=0; i<20; i++) {
        for(int j=0; j<2; j++) {
            for(int k=0; k<2; k++) {
                for(int l=0; l<2; l++) {
                    dp[i][j][k][l].first = -1;
                }
            }
        }
    }

    while(a.size() < b.size()) {
        a.insert(a.begin(), '0');
    }

    cout<<solve(0, 1, 1, 0).second;

    return 0;
}
