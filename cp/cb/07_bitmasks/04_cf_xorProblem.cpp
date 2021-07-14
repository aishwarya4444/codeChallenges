/*
https://codeforces.com/problemset/problem/959/F
https://codeforces.com/blog/entry/58712

if we took 2D DP array as per description
    - n = 10^5
    - xor = 2^20 = 10^6
then dp[10^5][10^6] would have given MLE

recurrence would have looked like
dp[i][xor] = dp[i-1][xor]      // do not include a[i] in xor
           + dp[i-1][xor^a[i]] //        include a[i] in xor
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9+7;
int a[100001];
bool seen[1<<20];
vector<int> visited;
vector<pair<int, int> > qry[100001];
int res[100001];
int n, q, l, x;

int main() {
    int ans = 1, j, query, L;

    cin>>n>>q;
    for(int i=1; i<=n; i++) {
        cin>>a[i];
    }
    memset(seen, false, sizeof seen);
    for(query=1; query<=q; query++) {
        cin>>l>>x;
        qry[l].push_back({x, query});
    }

    visited.push_back(0);
    seen[0] = true;
    for(int i=1; i<=n; i++) {
        if(seen[a[i]]) {
            ans = (2*ans)%mod;
        } else {
            for(j=0, L=visited.size(); j<L; j++) {
                visited.push_back(visited[j]^a[i]);
                seen[visited.back()] = true;
            }
        }

        for(int l=0; l<qry[i].size(); l++) {
            x     = qry[i][l].first;
            query = qry[i][l].second;
            res[query] = ans*seen[x];
        }
    }

    for(query=1; query<=q; query++) {
        cout<<res[query]<<endl;
    }

    return 0;
}
