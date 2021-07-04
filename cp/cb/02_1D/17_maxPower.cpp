#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*
https://leetcode.com/problems/maximum-product-subarray/
https://leetcode.com/submissions/detail/327297257/
*/

/*
max +ive sum
dp[i][0] = max(a[i], a[i]*dp[i-1][0]) .. if a[i]>0
         = a[i]*dp[i-1][1]            .. if a[i]<0

min -ive sum
dp[i][1] = a[i]*dp[i-1][1]            .. if a[i]>0
         = min(a[i]*dp[i-1][0], a[i]) .. if a[i]<0

*/
int main() {
    int n;

    cin>>n;

    ll num;
    ll dp[n][2], res;

    memset(dp, 0, sizeof(dp));

    cin>>num;
    res = num;
    if(num>0) {
        dp[0][0] = num;
    } else {
        dp[0][1] = num;
    }
    for(int i=1; i<n; i++) {
        cin>>num;
        if(num>0) {
            dp[i][0] = max(num*dp[i-1][0], num);
            dp[i][1] = num*dp[i-1][1];
        } else {
            dp[i][0] = num*dp[i-1][1];
            dp[i][1] = min(num*dp[i-1][0], num);
        }
        res = max({res, dp[i][0], dp[i][1]});
    }

    cout<<res;

    return 0;

}
