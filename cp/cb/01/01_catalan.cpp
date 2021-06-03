/*
Print nth Catalan Number. The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14,.. .

Input Format
One integer n

Constraints
1 <= N <= 100

Output Format
Print the catalan number at position N.

Sample Input
10
Sample Output
16796
*/

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	long long dp[n+1] = {0LL};

	dp[0] = 1LL;
	dp[1] = 1LL;

	for(int i=2; i<=n; i++) {
		for(int j=0; j<i; j++) {
			dp[i] += dp[j]*dp[i-1-j];
		}
	}

	cout<<dp[n];

	return 0;
}