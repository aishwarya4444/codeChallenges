/*
https://www.geeksforgeeks.org/maximum-sum-rectangle-in-a-2d-matrix-dp-27/
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
// grid
int a[1001][1001];

int main() {
    int t, r, c, val, ans, sum, maxSum;

    cin>>t;
    while(t--) {
        cin>>n>>m;
        memset(a, 0, sizeof a);

        for(r=1; r<=n; r++) {
            for(c=1; c<=m; c++) {
                cin>>a[r][c];
                a[r][c] += a[r][c-1];
            }
        }

        ans = a[1][1];
        for(int c1=1; c1<=m; c1++) {
            for(int c2=c1; c2<=m; c2++) {
                sum = 0;
                maxSum = ans;
                for(r=1; r<=n; r++) {
                    val = a[r][c2]-a[r][c1-1];
                    sum += val;
                    if(sum<val) sum = val;
                    if(maxSum<sum) maxSum = sum;
                }
                ans = max(ans, maxSum);
            }
        }

        cout<<ans<<endl;
    }

    return 0;
}
