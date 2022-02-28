/*
Let's define a new game of snakes and ladders.
There is only one dimension of n cells.
Each cell either contains a snake or ladder.
One can simply take a jump of not more than k cells.
A person cannot step on a snake.
However, s/he can jump over a snake.
Alice is excited to play this game and is asking you to calculate the number of ways to finish the game.
Game starts at 1st cell and ends at the nth cell.
It is guaranteed that there is a ladder at the 1st cell.
Since the number can be large, output the answer modulo (10^9+7).

Input Format
First line contains 2 integers N and K, denoting the number of cells and the maximum possible jump respectively.
The next line contains N integers, x1, x2,…., xN, where xi is either 0 or 1. xi=0 denotes that there is a ladder in ith cell, xi=1 denotes that there is a snake in ith cell.

Constraints
1<=N<=10^4 1<=K<=10^4 0<=xi<=1

Output Format
Output a single integer denoting the number of ways to finish the game modulo (10^9+7).

Sample Input
5 2
0 0 0 1 0
Sample Output
2

Explanation
There are 2 ways to reach the 5th cell - [1,2,3,5] and [1,3,5].
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int snake[10001];
ll dp[10001];
int n, k;
const int mod=1e9+7;

ll dfs(int i) {
	if(i==1) {
		return 1;
	}

	if(snake[i] || i<1) {
		return 0;
	}

	if(dp[i]!=0) {
		return dp[i];
	}

	ll ways = 0;
	for(int step=1; step<=k; step++) {
		ways += dfs(i-step);
		ways %= mod;
	}

	return dp[i] = ways;
}

ll bottomUp() {
	dp[1] = 1;

	for(int i=2; i<=n; i++) {
		if(snake[i]==0) {
			for(int j=1; j<=k; j++) {
				if(i-j<1) {
					break;
				}
				dp[i] += dp[i-j];
				dp[i] %= mod;
			}
		}
	}

	return dp[n];
}

ll solve(int pos) {
	// check snake first as last index can have and we will not reach it
	if(snake[pos]) return 0;
	if(pos==n) return 1;

	if(dp[pos] != -1) {
		return dp[pos];
	}

	ll ans = 0;
	for(int step=1; step<=k; step++) {
		if(pos+step>n) break;
		ans = (ans + solve(pos+step)) % mod;
	}

	return dp[pos] = ans;
}

int main() {
	cin>>n>>k;

    for(int i=1; i<=n; i++) {
    	cin>>snake[i];
    }

    // cout<<dfs(n);
    // cout<<bottomUp();

    memset(dp, -1, sizeof dp);
    cout<<solve(1);

    return 0;
}
