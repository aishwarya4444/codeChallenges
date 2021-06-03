/*
Given a value N, if we want to make change for N cents,
and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins,
In how many ways can we make the change?
The order of coins doesn’t matter.

Input Format
First line of input contain two space separated integers N and M.
Second line of input contains M space separated integers - value of coins.

Constraints
1<=N<=250 1<=m<=50 1 <= Si <= 50

Output Format
Output a single integer denoting the number of ways to make the given change using given coin denominations.

Sample Input
10 4
2 5 3 6
Sample Output
5
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[50][251];
int coins[50];

int main() {
	int n, m;

	cin>>n>>m;

	for(int i=0; i<m; i++) {
		cin>>coins[i];
	}

	for(int r=0; r<m; r++) {
		dp[r][0] = 1;
	}

	for(int r=0; r<m; r++) {
		for(int c=1; c<=n; c++) {
			int w1 = 0;
			int w2 = 0;
			if(r > 0) {
				w1 = dp[r-1][c];
			}
			if(c>=coins[r]) {
				w2 = dp[r][c-coins[r]];
			}
			dp[r][c] = w1+w2;
		}
	}

	cout<<dp[m-1][n];

	return 0;
}
