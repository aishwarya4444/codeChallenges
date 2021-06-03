/*
Given a string s and m queries.
Each query consists of (l,r) where 1 <= l <= r <= n(size of string).

You need to print whether l to r is a palindromic string or not.

A string can be called palindrome if its reverse is same as itself . Ex - "aba" .

Input Format
First line contains n Second lines contains a string of length n.
Next line contains m where m is the number of queries.
Next m lines contains two integers l,r as described in the question.

Constraints
n <= 1000

m <= 100000

Output Format
for every query from l to r print "YES" if s[l…..r] is palindrome else print "NO" without quotes in a new line.

Sample Input
5
abbac
2
1 4
2 4
Sample Output
YES
NO
Explanation
s[1….4]="abba", it is a palindrome.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool dp[1000][1000];

int main() {
	int n, m;
	string s;

	cin>>n;
	cin>>s;

	for(int r=0; r<n; r++) {
		dp[r][r] = true;
	}

	for(int r=n-1; r>=0; r--) {
		for(int c=r+1; c<n; c++) {
			if(s[r]==s[c] && (dp[r+1][c-1] || c-r==1)) {
				dp[r][c] = true;
			}
		}
	}

	cin>>m;
	while(m--) {
		int l, r;
		cin>>l>>r;
		l--;
		r--;
		if(dp[l][r]) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}

	return 0;
}
