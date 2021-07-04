#include<bits/stdc++.h>
using namespace std;

int fib(int n) {
    if(n==0 || n==1) {
        return n;
    }

    int ans;
    ans = fib(n-1) + fib(n-2);
    return ans;
}

int dp[100];
int fibTopDown(int n) {
    if(n==0 || n==1) {
        return n;
    }

    if(dp[n]!=0) {
        return dp[n];
    }

    int ans;
    ans = fib(n-1) + fib(n-2);
    return dp[n] = ans;
}

int fibBottomUp(int n) {
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];
}

int main() {
    int n;
    cin>>n;
    cout<<fib(n);
    return 0;
}