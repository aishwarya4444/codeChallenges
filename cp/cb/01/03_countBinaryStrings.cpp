/*
You are provided an integers N. You need to count all possible distinct binary strings of length N such that there are no consecutive 1’s.

Input Format
First line contains integer t which is number of test case. For each test case, it contains an integer n which is the the length of Binary String.

Constraints
1<=t<=100 1<=n<=90

Output Format
Print the number of all possible binary strings.

Sample Input
2
2
3
Sample Output
3
5
Explanation
1st test case : 00, 01, 10 2nd test case : 000, 001, 010, 100, 101
*/

// https://leetcode.com/discuss/general-discussion/1287402/count-number-of-binary-strings-without-consecutive-1s
// shortcut is fibonacci

// top down
#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll dp[91][2];

ll solve(int pos, int ones, int n) {
	if(ones==2) return 0;
	if(pos==n) return 1;

	if(dp[pos][ones] != -1) {
		return dp[pos][ones];
	}

	ll ans = 0;
	// keep 0 at current place
	ans += solve(pos+1, 0, n);
	// keep 1 at current place
	ans += solve(pos+1, ones+1, n);

	return dp[pos][ones] = ans;
}

int main() {
	int t, n;

	cin>>t;

	while(t--) {
		cin>>n;

		memset(dp, -1, sizeof dp);

		cout<<solve(0, 0, n)<<endl;
	}

	return 0;
}

// bottom up
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[2][91];

int main() {
	int n, t;

	dp[0][1] = 1LL;
	dp[1][1] = 1LL;
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i=2; i<=n; i++) {
			dp[0][i] = dp[0][i-1]+dp[1][i-1];
			dp[1][i] = dp[0][i-1];
		}
		cout<<dp[0][n]+dp[1][n]<<endl;
	}

	return 0;
}
