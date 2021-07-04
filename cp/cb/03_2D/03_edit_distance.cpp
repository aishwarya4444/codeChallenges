#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[2001][2001];

int main() {
    string a, b;
    int r, c, A, B;

    cin>>a;
    cin>>b;

    A = a.size();
    B = b.size();

    for(r=1; r<=A; r++) {
        dp[r][0] = r;
    }

    for(c=1; c<=B; c++) {
        dp[0][c] = c;
    }

    for(r=1; r<=A; r++) {
        for(c=1; c<=B; c++) {
            if(a[r-1]==b[c-1]) {
                dp[r][c] = dp[r-1][c-1];
            } else {
                dp[r][c] = 1 + min({dp[r-1][c-1], dp[r][c-1], dp[r-1][c]});
            }
        }
    }

    cout<<dp[A][B];

    return 0;

}
