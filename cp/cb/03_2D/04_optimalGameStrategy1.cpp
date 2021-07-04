/*
https://leetcode.com/problems/predict-the-winner/

Piyush and Nimit are playing a coin game.
They are given n coins with values x1, x2 …. xn where 'n' is always even.
They take alternate terms.
In each turn, a player picks either the first coin or the last coin from the row and removes it from the row.
The value of coin is received by that player.
Determine the maximum value that Piyush can win with if he moves first. Both the players play optimally.

Input Format
First line contains the number of coins 'n'.
Second line contains n space separated integers where ith index denotes the value of ith coin.

Constraints
1 < N <= 30 , N is always even
0 <= Ai <= 1000000

Output Format
Print a single line with the maximum possible value that Piyush can win with.

Sample Input
4
1 2 3 4

Sample Output
6

Explanation
Piyush will pick the coin 4.
Then Nimit can pick either 1 or 3.
In both the cases piyush picks coin 2 and wins with a total of 6.
*/

// Top - Down
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> a;
int n;
ll dp[30][30];

ll solve(int i, int j) {
    if(i>j) {
        return 0;
    }

    if(dp[i][j]!=-1) {
        return dp[i][j];
    }

    ll op1 = a[i] + min(solve(i+1, j-1), solve(i+2, j));
    ll op2 = a[j] + min(solve(i, j-2), solve(i+1, j-1));

    return dp[i][j] = max(op1, op2);
}

int main() {
    int val;

    cin>>n;

    memset(dp, -1, sizeof(dp));

    for(int i=1; i<=n; i++) {
        cin>>val;
        a.push_back(val);
    }

    cout<<solve(0, n-1);

    return 0;

}


// Bottom - Up
#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> a;
int n;
ll dp[30][30];

ll solve() {

    for(int i=n-1; i>=0; i--) {
        dp[i][i] = a[i];
        for(int j=i+1; j<n; j++) {
            ll op1 = a[i] + min(
                i+1>j-1 ? 0 : dp[i+1][j-1],
                i+2>j   ? 0 : dp[i+2][j]
            );
            ll op2 = a[j] + min(
                i>j-2   ? 0 : dp[i][j-2],
                i+1>j-1 ? 0 : dp[i+1][j-1]
            );
            dp[i][j] = max(op1, op2);
        }
    }

    return dp[0][n-1];
}

int main() {
    int val;

    cin>>n;

    memset(dp, 0, sizeof(dp));

    for(int i=1; i<=n; i++) {
        cin>>val;
        a.push_back(val);
    }

    cout<<solve();

    return 0;

}

