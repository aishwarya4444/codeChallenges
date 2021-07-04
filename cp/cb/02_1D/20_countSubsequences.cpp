/*
https://www.spoj.com/problems/DSUBSEQ/
https://github.com/rajonaust/SPOJ/blob/master/DSUBSEQ%20-%20Distinct%20Subsequence
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

string s;
int n;
int last[26];
ll dp[100001];
const int mod = 1e9+7;

void solve() {

    memset(last, 0, sizeof(last));
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        dp[i] = (2*dp[i-1]-dp[last[s[i]-'A']-1]+mod)%mod;
        last[s[i]-'A'] = i;
    }

    cout<<dp[n]<<endl;
}

int main() {
    int t;

    cin>>t;

    while(t--) {
        cin>>s;
        n = s.size();
        s = '_'+s;

        solve();
    }

    return 0;

}
