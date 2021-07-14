/*
https://www.codechef.com/problems/SHOPTRIP

Prateek solution
https://www.codechef.com/viewsolution/16311283
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

struct point {
    int x, y;
};

ld getDistance(point p1, point p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return sqrt(dx*dx + dy*dy);
}

point shops[37];
int products[37];
ld dist[37][37];
ld dp[37][1<<13];
int n, k;

ld solve(int i, int mask) {
    if(mask == ( (1<<k) - 1 ) ) {
        return dist[i][0];
    }
    if(dp[i][mask] != -1) {
        return dp[i][mask];
    }

    ld ans = INT_MAX;
    for(int j=1; j<=n; j++) {
        // bracket () is important .. commented line below did not work
        // if(mask|products[j] == mask) continue;
        if((mask|products[j]) == mask) continue;
        ans = min( ans, dist[i][j] + solve(j, mask|products[j]) );
    }
    return dp[i][mask] = ans;
}

// memset did not work with double type array
//   - https://stackoverflow.com/questions/37780779/memset-to-int-max-in-c
//   - https://stackoverflow.com/questions/27581320/using-memset-in-double-type-array
//   - https://codeforces.com/blog/entry/10340
void initDp() {
    for(int i=0; i<37; i++) {
        for(int mask =0; mask<(1<<13); mask++) {
            dp[i][mask] = -1;
        }
    }
}

int main() {
    int t;
    string productMask;
    int x, y;

    shops[0] = {0, 0};
    products[0] = 0;

    cin>>t;
    while(t--) {
        cin>>n>>k;

        for(int i=1; i<=n; i++) {
            cin>>x>>y;
            shops[i] = {x, y};
        }

        int tmpMasks = 0;
        for(int i=1; i<=n; i++) {
            // mask is input in binary
            // convert it to integer
            int mask = 0;
            cin>>productMask;
            for(char ch: productMask) {
                mask = 2*mask + (ch-'0');
            }
            products[i] = mask;
            tmpMasks |= mask;
        }

        if(tmpMasks != ( (1<<k) - 1 )) {
            cout<<-1<<endl;
            continue;
        }

        for(int i=0; i<=n; i++) {
            dist[i][i] = 0;
            for(int j=i+1; j<=n; j++) {
                dist[i][j] = dist[j][i] = getDistance(shops[i], shops[j]);
            }
        }

        initDp();
        // solve(shop visited, mask of products collected)
        cout<<fixed<<setprecision(9)<<solve(0, 0)<<endl;
    }

    return 0;
}
