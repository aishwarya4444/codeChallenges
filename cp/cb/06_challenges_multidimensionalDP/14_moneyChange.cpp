/*
Given a big amount N and the array of denominations S.
Assuming infinite supply of each of S = {S1,S2….Sm} denominations, find the number of ways to make change for N cents.

Input Format
First line contains an integer T denoting the total number of test cases.
For every test case, there are three lines.
First line will contain an integer 'M' denoting the size of array.
The second line contains M space-separated integers A1, A2, …, Am denoting the elements of the array.
The third line contains an integer 'N' denoting the cents.

Constraints
1 <= T <= 10
1 <= M <= 500
1 <= S[i] <= 1000
1 <= N <= 1000000

Output Format
Print number of possible ways to make change for N cents in a new line.
Since answers can be large, print answer % (1000000000 + 7).

Sample Input
2
3
1 2 3
4
4
2 5 3 6
10

Sample Output
4
5

Explanation
For N = 4 and S = {1,2,3}, there are four solutions:
{1,1,1,1},{1,1,2},{2,2},{1,3}.
So output should be 4.

For N = 10 and S = {2, 5, 3, 6}, there are five solutions:
{2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}.
So the output should be 5.
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;
int s[501];
// ll dp[2][1000001];
ll dp[1000001];

void solve() {
    memset(dp, 0, sizeof dp);
    dp[0]=1;
    for(int i=0;i<m;i++)
    {
        for(int j=s[i];j<=n;j++)
            dp[j]=(dp[j]+dp[j-s[i]])%(1000000007);
    }

    cout<<dp[n]<<endl;
}

int main() {
    int t;

    cin>>t;
    while(t--) {
        cin>>m;
        for(int i=0; i<m; i++) {
            cin>>s[i];
        }
        cin>>n;

        // dp[0][0] = dp[1][0] = 1;
        // for(int r=0; r<m; r++) {
        //     for(int c=1; c<=n; c++) {
        //         dp[r%2][c] = 0;
        //         if(r>0) {
        //             dp[r%2][c] += dp[(r+1)%2][c];
        //             dp[r%2][c] %= (1000000007);
        //         }
        //         if(c>=s[r]) {
        //             dp[r%2][c] += dp[r%2][c-s[r]];
        //             dp[r%2][c] %= (1000000007);
        //         }
        //     }
        // }
        // cout<<dp[(m-1)%2][n]<<endl;
        solve();
    }

    return 0;
}
