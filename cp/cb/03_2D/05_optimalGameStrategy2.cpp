#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> a;
int n;
ll dp[5000][5000];

ll solve() {

    for(int i=n-1; i>=0; i--) {
        dp[i][i] = a[i];
        for(int j=i+1; j<n; j++) {
            ll op1 = a[i] + min(
                i+1>j-1 ? 0 : dp[i+1][j-1],
                i+2>j   ? 0 : dp[i+2][j]
            );
            ll op2 = a[j] + min(
                i>j-2   ? 0 : dp[i][j-2],
                i+1>j-1 ? 0 : dp[i+1][j-1]
            );
            dp[i][j] = max(op1, op2);
        }
    }

    return dp[0][n-1];
}

int main() {
    int val;

    cin>>n;

    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++) {
        cin>>val;
        a.push_back(val);
    }

    cout<<solve();

    return 0;

}
