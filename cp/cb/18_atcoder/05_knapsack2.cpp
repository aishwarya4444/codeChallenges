#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp[100000001];

int main() {
    int N, W;
    int w[101];
    int v[101];

    cin>>N>>W;

    for(int i=0; i<N; i++) {
        cin>>w[i]>>v[i];
    }

    for(int cap=0; cap<=W; cap++) {
        if(w[0] <= cap) {
            dp[cap] = v[0];
        }
    }

    for(int i=1; i<N; i++) {
        // if we move from 0 -> W
        // we might change lower value of 'cap'
        // and will give incorrect result
        // hence we go in reverse direction
        for(int cap=W; cap>=0; cap--) {
            int way1 = 0, way2 = 0;
            way1 = dp[cap];
            if(w[i] <= cap) {
                way2 = v[i] + dp[cap-w[i]];
            }
            dp[cap] = max(way1, way2);
        }
    }

    cout<<dp[W];

    return 0;
}