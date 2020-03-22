#include<iostream>
#include<vector>
using namespace std;

int main(void) {
    int N, M, K;
    int n, m, res=0, ones=0;
    char ch;

    cin>>N>>M>>K;

    vector<vector<int> > dp(N+1, vector<int>(M+1, 0));

    for(n=0; n<N; n++) {
        for(m=0; m<M; m++) {
            cin>>ch;
            if(ch == '*') {
                dp[n+1][m+1] = 1;
            }
        }
    }

    for(n=1; n<=N; n++) {
        for(m=1; m<=M; m++) {
            dp[n][m] += dp[n][m-1];
        }
    }

    for(m=1; m<=M; m++) {
        for(n=1; n<=N; n++) {
            dp[n][m] += dp[n-1][m];
        }
    }

    K--;
    for(n=1; n+K<=N; n++) {
        for(m=1; m+K<=M; m++) {
            ones = dp[n+K][m+K] - dp[n-1][m+K] - dp[n+K][m-1] + dp[n-1][m-1];
            res = max(res, ones);
        }
    }

    cout<<res<<endl;

    return 0;
}

/*
s
3 3 2
*.*
**.
*..

*/