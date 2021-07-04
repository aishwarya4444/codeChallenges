#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[1001][1001];
int cap[1001];
int val[1001];

int solve(int i, int S, int N) {
    if(i==N) {
        return 0;
    }

    if(dp[i][S]!=-1) {
        return dp[i][S];
    }

    int choice1=0, choice2=0;

    if(S-cap[i]>=0) {
        choice1 = val[i] + solve(i+1, S-cap[i], N);
    }

    choice2 = solve(i+1, S, N);

    return dp[i][S] = max(choice1, choice2);
}

int main() {
    int S, N;

    cin>>N>>S;

    for(int i=0; i<N; i++) {
        cin>>cap[i];
    }

    for(int i=0; i<N; i++) {
        cin>>val[i];
    }

    memset(dp, -1, sizeof(dp));

    cout<<solve(0, S, N);

    return 0;

}