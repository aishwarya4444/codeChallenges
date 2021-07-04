/*
https://www.spoj.com/problems/BRIDGE/
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<pair<int, int> > ab;
int n;

int lis() {
    vector<int> dp(n, 1);

    int len = 1;

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(ab[j].second<=ab[i].second && dp[i]<1+dp[j]) {
                dp[i] = 1+dp[j];
                len = max(len, dp[i]);
            }
        }
    }

    return len;
}

/*
a1 a2 a3 a4
===========
b1 b2 b3 b4
*/
int main() {
    int t, b;

    cin>>t;

    while(t--) {
        cin>>n;
        int a[n];

        for(int i=0; i<n; i++) {
            cin>>a[i];
        }

        for(int i=0; i<n; i++) {
            cin>>b;
            ab.push_back({a[i], b});
        }

        sort(ab.begin(), ab.end());

        cout<<lis()<<endl;
        ab.clear();
    }

    return 0;

}
