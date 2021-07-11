/*
https://www.codechef.com/problems/TSHIRTS

coding blocks
https://www.youtube.com/watch?v=8bdXzqabYls

kartik
https://www.youtube.com/watch?v=Smem2tVQQXU
https://www.codechef.com/viewsolution/28505745
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9+7;
int dp[1024][101];
int n;
unordered_map<int, vector<int> > g;

int solve(int mask, int tshirt) {
    if(mask == (1<<n)-1) {
        return 1;
    }
    if(tshirt > 100) {
        return 0;
    }
    if(dp[mask][tshirt] != -1) {
        return dp[mask][tshirt];
    }

    ll ways = solve(mask, tshirt+1);

    for(int person: g[tshirt]) {
        if(mask & (1<<person)) continue;
        ways = (ways + solve(mask | (1<<person), tshirt+1))%mod;
    }

    return dp[mask][tshirt] = ways;
}

int main() {
    int t;

    cin>>t;
    while(t--) {
        g.clear();
        memset(dp, -1, sizeof dp);

        cin>>n;
        cin.ignore();
        for(int person=0; person<n; person++) {
            string str;
            string tshirt;
            getline(cin, str);
            stringstream ss(str);
            while(ss>>tshirt) {
                g[stoi(tshirt)].push_back(person);
            }
        }

        cout<<solve(0,1)<<endl;
    }

    return 0;
}
