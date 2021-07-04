/*

https://www.codechef.com/ZCOPRAC/problems/ZCO14004

In IPL 2025, the amount that each player is paid varies from match to match.
The match fee depends on the quality of opposition, the venue etc.

The match fees for each match in the new season have been announced in advance.
Each team has to enforce a mandatory rotation policy so that no player ever plays three matches in a row during the season.

Nikhil is the captain and chooses the team for each match.
He wants to allocate a playing schedule for himself to maximize his earnings through match fees during the season.

Input Format
Line 1: A single integer N, the number of games in the IPL season.

Line 2: N non-negative integers, where the integer in position i represents the fee for match i.

Constraints
N < 1000000 a[i] < 1000

Output Format
The output consists of a single non-negative integer, the maximum amount of money that Nikhil can earn during this IPL season.

Sample Input
8
3 2 3 2 3 5 1 3
Sample Output
17
Explanation
(Explanation: 3+3+3+5+3)
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll a[1000001];
ll dp[1000001];

int main() {
	int n;
	ll ans, sum=0;

	cin>>n;

	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum += a[i];
	}

	dp[1] = a[1];
	dp[2] = a[2];
	dp[3] = a[3];

	for(int i=4; i<=n; i++) {
		dp[i] = a[i]+min(dp[i-1], min(dp[i-2], dp[i-3]));
	}

	if(n==1) {
		ans = dp[1];
	} else if(n==2) {
		ans = min(dp[1], dp[2]);
	} else {
		ans = min({dp[n], dp[n-1], dp[n-2]});
	}

	cout<<sum-ans;

	return 0;
}
