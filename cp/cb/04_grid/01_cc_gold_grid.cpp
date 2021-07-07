/*
https://www.codechef.com/problems/SSJG

Sayan's friend has left a gamefield organized as an N∗N grid.
Each square in the grid either has or does not have a gold coin.
He has to divide the gamefield with his three other friends as follows:
    he will draw one horizontal line and one vertical line to divide the field into four rectangles.
His friends will choose three of the four smaller fields and he gets the last one.

He wants to divide the field so that he gets the maximum number of goldcoins, assuming that his friends will pick the best three rectangles.

Input Format
The first line contains 2 integers N and M, the size of the gamefield and the number of gold coins in the field respectively.

The next M lines contain two integers, Xi and Yi, giving the coordinated of the i-th gold coin.
It is guaranteed that all Xi and Yi are pairwise distinct.

Constraints
1 ≤ N ≤ 1000
0 ≤ M ≤ N^2
1 ≤ Xi,Yi ≤ N

Output Format
Output one integer, the maximum number of gold coins Sayan can get.

Sample Input
6 13
1 2
1 3
2 1
2 4
2 5
3 2
4 2
4 3
4 6
5 1
5 4
5 5
6 2

Sample Output
3
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int m, n;
// grid
int a[1001][1001];
int s1, s2, s3, s4;

int totalGold(int r1, int c1, int r2, int c2) {
    return a[r2][c2] - a[r2][c1-1] - a[r1-1][c2] + a[r1-1][c1-1];
}

int main() {
    int r, c, ans=0;

    cin>>n>>m;

    while(m--) {
        cin>>r>>c;
        a[r][c] = 1;
    }

    for(r=1; r<=n; r++) {
        for(c=1; c<=n; c++) {
            a[r][c] += a[r][c-1] + a[r-1][c] - a[r-1][c-1];
        }
    }

    for(r=2; r<n; r++) {
        for(c=2; c<n; c++) {
            s1 = totalGold(1, 1, r-1, c-1);
            s2 = totalGold(1, c, r-1, n);
            s3 = totalGold(r, 1, n, c-1);
            s4 = totalGold(r, c, n, n);
            ans = max(ans, min({s1, s2, s3, s4}));
        }
    }

    cout<<ans;

    return 0;
}
