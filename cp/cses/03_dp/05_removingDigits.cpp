/*
https://cses.fi/problemset/task/1637
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int dp[1000001];

int solve(int num) {;
	if(num==0) {
		return 0;
	}

	if(dp[num]!=-1) {
		return dp[num];
	}

	unordered_set<int> digits;
	int number = num;
	while(number) {
		digits.insert(number%10);
		number /= 10;
	}

	int ans = 1e9;
	for(int digit: digits) {
		if(digit==0) continue; /* subtracting 0 will call solve(num) infinitely */
		ans = min(ans, 1+solve(num-digit));
	}

	return dp[num] = ans;
}

int main() {
	int n;

	cin>>n;
	memset(dp, -1, sizeof dp);
	cout<<solve(n);

	return 0;
}
