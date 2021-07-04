/*
https://codeforces.com/problemset/problem/332/B

https://codeforces.com/blog/entry/8447?#comment-670236
https://codeforces.com/contest/332/submission/88184280
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1000000007;
ll sum[200001];
ll dp[200001][3];


int main() {
    int n, k;
    int a, b;
    ll sumReq;

    cin>>n>>k;
    for(int i=1; i<=n; i++) {
        cin>>sum[i];
        sum[i] += sum[i-1];
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=2; j++) {
            if(i<k) continue;
            if(dp[i-1][j] < dp[i-k][j-1]+sum[i]-sum[i-k]) {
                sumReq = dp[i-k][j-1];
                b = i-k+1;
                dp[i][j] = dp[i-k][j-1]+sum[i]-sum[i-k];
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    for(int i=k; i<b; i++) {
        if(sumReq == sum[i]-sum[i-k]) {
        // if(sumReq == dp[i][1]) {
            a = i-k+1;
            break;
        }
    }

    cout<<a<<' '<<b;

    return 0;

}
