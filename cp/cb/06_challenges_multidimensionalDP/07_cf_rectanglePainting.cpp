/*
https://codeforces.com/contest/1198/problem/D -> cost = max(w,h)
https://codeforces.com/contest/1198/problem/E -> cost = min(w,h) Dinic Algorithm

https://codeforces.com/blog/entry/68812
Let's solve the problem for rectangle 𝑊×𝐻 (𝑊≥𝐻).
Of course, we can cover all rectangle with itself for cost 𝑊.
To get something smaller than 𝑊 we have to leave at least one column uncovered —
otherwise we pay at least sum of 𝑤 over all rectangles which is at least 𝑊.
This gives us an idea to use DP on rectangles to solve the problem:
𝑑𝑝[𝑥1][𝑥2][𝑦1][𝑦2] is minimal cost to cover the rectangle [𝑥1;𝑥2)×[𝑦1;𝑦2).
It is initialized by max(𝑥2−𝑥1,𝑦2−𝑦1), and we have to try not to cover every column/row.
Of course, we have to check if it is all white from the beginning;
to do that we will precalculate 2D prefix sums.
Total complexity is 𝑂(𝑛5).

https://www.programmersought.com/article/79352473663/
https://www.cnblogs.com/wawcac-blog/p/11288791.html
https://www.codetd.com/en/article/6930012
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp[51][51][51][51];
int n;
int g[51][51];

int solve(int x1, int y1, int x2, int y2) {
    if(x1==x2 && y1==y2) {
        return g[x1][y1];
    }

    if(dp[x1][y1][x2][y2] != -1) {
        return dp[x1][y1][x2][y2];
    }

    int ans = max(x2-x1+1, y2-y1+1);

    for(int r=x1+1; r<=x2; r++) {
        ans = min(ans, solve(x1, y1, r-1, y2) + solve(r, y1, x2, y2));
    }

    for(int c=y1+1; c<=y2; c++) {
        ans = min(ans, solve(x1, y1, x2, c-1) + solve(x1, c, x2, y2));
    }

    return dp[x1][y1][x2][y2] = ans;
}

int main() {
    char ch;
    unordered_map<char, int> color = {{'#',1}, {'.',0}};

    cin>>n;
    memset(dp, -1, sizeof dp);

    for(int r=1; r<=n; r++) {
        for(int c=1; c<=n; c++) {
            cin>>ch;
            g[r][c] = color[ch];
        }
    }

    cout<<solve(1,1,n,n);

    return 0;
}
