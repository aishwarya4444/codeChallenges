/*
Vivek loves to play with array.
One day Vivek just came up with a new array game which was introduced to him by his friend Ujjwal.

The rules of the game are as follows:
Initially, there is an array, A , containing 'N' integers.
In each move, Vivek must divide the array into  two non-empty contiguous parts
such that the sum of the elements in the left part is equal  to the sum of the elements in the right part.
If Vivek can make such a move, he gets '1' point; otherwise, the game ends.

After each successful move, Vivek have to discards either the left part or the right part and continues playing by using
the remaining partition as array 'A'.

Vivek loves this game and wants your help getting the best score possible.
Given 'A', can you find and print the maximum number of points he can score?

Input Format
First line of input contains an integer T denoting number of test cases.
Each further Test case contains first line an integer 'N' , the size of array 'A'.
After that 'N' space separated integers denoting the elements of array.

Constraints
1 <= T <= 10 1 <= N <= 17000 0 <= A[i] <= 10^9

Output Format
For each test case, print Vivek's maximum possible score on a new line.

Sample Input
3
3
3 3 3
4
2 2 2 2
7
4 1 0 1 1 0 1

Sample Output
0
2
3
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long

int num[17001];
ll sum[17001];
 int dp[17001][17001];
// map<pair<int,int>, int > dp;
// this big array we cannot use
// there are no overlapping subproblems

ll csum(int i, int j) {
    return sum[j]-sum[i-1];
}

int solve(int l, int r) {
    if(l==r) {
        return 0;
    }

    if(dp[l][r] != -1) {
        return dp[l][r];
    }

    int ways = 0;
    for(int k=l+1; k<=r; k++) {
        if(csum(l, k-1) == csum(k, r)) {
           // dp[l][r] = max(dp[l][r], 1+max(solve(l, k-1), solve(k, r)));
            ways = max(ways, 1+max(solve(l, k-1), solve(k, r)));
            break;
        }
    }

    return dp[l][r] = ways;

   // return dp[l][r]==-1 ? 0 : dp[l][r];
}

int main() {
    int t, n;

    cin>>t;

    while(t--) {
        cin>>n;

        for(int i=1; i<=n; i++) {
            cin>>num[i];
            sum[i] = sum[i-1]+num[i];
        }

       // memset(dp, -1, sizeof(dp));

        cout<<solve(1, n)<<endl;
    }

    return 0;
}
