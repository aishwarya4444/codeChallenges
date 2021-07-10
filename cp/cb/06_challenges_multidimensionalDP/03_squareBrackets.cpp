/*
You are given:

a positive integer n.
an integer k, 1<=k<=n.
an increasing sequence of k integers 0 < s1 < s2 < ... < sk <= 2n.
You have to find out the number of proper brackets sequence of length 2n which contain
an opening bracket at k positions s1 < s2 < … < sk. These k positions will necessarily have
an opening bracket while the other positions can be either an opening bracket or a closing bracket.
Several proper bracket expressions:
[[]][[[]][]]
[[[][]]][][[]]
An improper bracket expression:
[[[][]]][]][[]]
There is exactly one proper expression of length 8 with opening brackets in positions 2, 5 and 7.

Input Format
The first line consists of number of test cases T. Each test case consists of two space seperated integers n and k.
Next line consists of k space seperated integers denoting positions of open brackets.

Constraints
1 <= n <= 50. 0 <= k <= n.

Output Format
The number of ways modulo 10^9+7.

Sample Input
5
1 1
1
1 1
2
2 1
1
3 1
2
4 2
5 7

Sample Output
1
0
2
3
2
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int dp[51][51];
int n, k;
bool positions[51];

int solve(int open, int close) {
    if(open==n && close==n) {
        return 1;
    }

    if(dp[open][close] != -1) {
        return dp[open][close];
    }

    int ways = 0;

    if(open<n && open>=close) {
        ways += solve(open+1, close);
    }
    if(close<n && open>close && positions[open+close+1]==false) {
        ways += solve(open, close+1);
    }

    return dp[open][close] = ways;
}

int main() {
    int t, pos;

    cin>>t;
    while(t--) {
        cin>>n>>k;
        memset(dp, -1, sizeof dp);
        memset(positions, false, sizeof positions);
        for(int i=1; i<=k; i++) {
            cin>>pos;
            positions[pos] = true;
        }
        cout<<solve(0,0)<<endl;
    }

    return 0;
}
