/*
https://codeforces.com/contest/429/problem/B

Summer is coming! It's time for Iahub and Iahubina to work out, as they both want to look hot at the beach.
The gym where they go is a matrix a with n lines and m columns.
Let number a[i][j] represents the calories burned by performing workout at the cell of gym in the i-th line and the j-th column.

Iahub starts with workout located at line 1 and column 1.
He needs to finish with workout a[n][m]. After finishing workout a[i][j], he can go to workout a[i + 1][j] or a[i][j + 1].
Similarly, Iahubina starts with workout a[n][1] and she needs to finish with workout a[1][m].
After finishing workout from cell a[i][j], she goes to either a[i][j + 1] or a[i - 1][j].

There is one additional condition for their training. They have to meet in exactly one cell of gym.
At that cell, none of them will work out.
They will talk about fast exponentiation (pretty odd small talk) and then both of them will move to the next workout.

If a workout was done by either Iahub or Iahubina, it counts as total gain.
Please plan a workout for Iahub and Iahubina such as total gain to be as big as possible.
Note, that Iahub and Iahubina can perform workouts with different speed, so the number of cells that they use to reach meet cell may differs.

Input
The first line of the input contains two integers n and m (3 ≤ n, m ≤ 1000).
Each of the next n lines contains m integers: j-th number from i-th line denotes element a[i][j] (0 ≤ a[i][j] ≤ 105).

Output
The output contains a single number — the maximum total gain possible.

Examples
input
3 3
100 100 100
100 1 100
100 100 100

output
800
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
//  boy starts from [1][1] to intersection ... and [n][m] to intersection
ll b0[1001][1001], b1[1001][1001];
// girl starts from [n][1] to intersection ... and [1][m] to intersection
ll g0[1001][1001], g1[1001][1001];
// grid
int a[1001][1001];

int main() {
    int r, c;
    ll ans = 0;
    ll op1, op2;

    cin>>n>>m;
    for(r=1; r<=n; r++) {
        for(c=1; c<=m; c++) {
            cin>>a[r][c];
        }
    }

    // boy starts from [1][1]
    for(r=1; r<=n; r++) {
        for(c=1; c<=m; c++) {
            b0[r][c] = a[r][c] + max(b0[r-1][c], b0[r][c-1]);
        }
    }
    // boy starts from [n][m]
    for(r=n; r>=1; r--) {
        for(c=m; c>=1; c--) {
            b1[r][c] = a[r][c] + max(b1[r+1][c], b1[r][c+1]);
        }
    }

    // girl starts from [n][1]
    for(r=n; r>=1; r--) {
        for(c=1; c<=m; c++) {
            g0[r][c] = a[r][c] + max(g0[r+1][c], g0[r][c-1]);
        }
    }
    // girl starts from [1][m]
    for(r=1; r<=n; r++) {
        for(c=m; c>=1; c--) {
            g1[r][c] = a[r][c] + max(g1[r-1][c], g1[r][c+1]);
        }
    }

    // consider all possible intersection points [r][c]
    for(r=2; r<n; r++) {
        for(c=2; c<m; c++) {
            // boy comes from top [r-1][c]   ... girl comes from left [r][c-1]
            // boy leaves from down [r+1][c] ... girl leaves from right [r][c+1]
            op1 = b0[r-1][c] + b1[r+1][c] + g0[r][c-1] + g1[r][c+1];


            // boy comes from left [r][c-1]   ... girl comes from down [r+1][c]
            // boy leaves from right [r][c+1] ... girl leaves from top [r-1][c]
            op2 = b0[r][c-1] + b1[r][c+1] + g0[r+1][c] + g1[r-1][c];

            ans = max({ans, op1, op2});

        }
    }

    cout<<ans;

    return 0;
}
