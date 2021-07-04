/*
https://codeforces.com/problemset/problem/1114/D

You are given a line of 𝑛 colored squares in a row, numbered from 1 to 𝑛 from left to right.
The 𝑖-th square initially has the color 𝑐𝑖.

Let's say, that two squares 𝑖 and 𝑗 belong to the same connected component if 𝑐𝑖=𝑐𝑗, and 𝑐𝑖=𝑐𝑘 for all 𝑘 satisfying 𝑖<𝑘<𝑗.
In other words, all squares on the segment from 𝑖 to 𝑗 should have the same color.

For example, the line [3,3,3] has 1 connected component, while the line [5,2,4,4] has 3 connected components.

The game "flood fill" is played on the given line as follows:

At the start of the game you pick any starting square (this is not counted as a turn).
Then, in each game turn, change the color of the connected component containing the starting square to any other color.
Find the minimum number of turns needed for the entire line to be changed into a single color.

Input
The first line contains a single integer 𝑛 (1≤𝑛≤5000) — the number of squares.

The second line contains integers 𝑐1,𝑐2,…,𝑐𝑛 (1≤𝑐𝑖≤5000) — the initial colors of the squares.

Output
Print a single integer — the minimum number of the turns needed.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[5001][5001];

int main() {
    int n, ci;
    vector<int> color;

    cin>>n;

    cin>>ci;
    color.push_back(ci);
    for(int i=2; i<=n; i++) {
        cin>>ci;
        if(ci!=color.back()) {
            color.push_back(ci);
        }
    }

    n = color.size();

    for(int l=n-2; l>=0; l--) {
        for(int r=l+1; r<n; r++) {
            if(color[l]==color[r]) {
                if(r-l != 1) {
                    dp[l][r] = 1+dp[l+1][r-1];
                }
            } else {
                dp[l][r] = 1+min(dp[l+1][r], dp[l][r-1]);
            }
        }
    }

    cout<<dp[0][n-1];

    return 0;
}

/*
// editorial solution
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long int
#define F first
#define S second
#define pb push_back

using namespace std;
using namespace __gnu_pbds;

typedef tree<ll, null_type, less<ll>, rb_tree_tag,
        tree_order_statistics_node_update>
        new_data_set;

const ll N = 5005;

ll dp[N][N];

int main()
{
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    // ll t;
    // cin>>t;
    // while(t--)
    {
        ll i, j, k, n, m, ans = 0, cnt = 0, sum = 0;
        cin >> n;
        vector<ll> v(n);
        for (i = 0; i < n; i++) {
            cin >> v[i];
        }
        v.resize(unique(v.begin(), v.end()) - v.begin());
        n = v.size();
        for (j = 0; j < n; j++) {
            for (i = j; i >= 0; i--) {
                dp[i][j] = 1e9;
                if (i == j) {
                    dp[i][j] = 0;
                    continue;
                }
                if (v[i] == v[j] && j > i + 1) {
                    dp[i][j] = 1 + dp[i + 1][j - 1];
                }
                else {
                    dp[i][j] = min({dp[i][j], dp[i + 1][j] + 1, dp[i][j - 1] + 1});
                }
            }
        }
        cout << dp[0][n - 1];
    }
}
*/
