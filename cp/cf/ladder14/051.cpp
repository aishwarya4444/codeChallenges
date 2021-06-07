/*
https://codeforces.com/problemset/problem/505/C

Error 1:
Can't compile file:
program.cpp:10:20: error: size of array 'dp' is too large
 int dp[30001][30001];
                   ^
Error 2:
// int dp[30001][2001];
// memset(dp, -1, sizeof(dp));
// gave error for
// 1 30000
// 30000



Error 3:
unordered_map<int, unordered_map<int, int> > dp;
if(dp.count(src) && dp[src].count(jump))

gave error for
30000 140
140
140
..
..
*/

#include<bits/stdc++.h>
using namespace std;

int island;
int gems[30001];
int dp[30110][2001];

int totalGems(int src, int jump) {
	if(dp[src][jump]!=-1) {
		return dp[src][jump];
	}

	int res = 0;

	for(int i=-1; i<=1; i++) {
		int des = src + jump + i;
		if(src<des && des<=island) {
			res = max(res, totalGems(des, jump+i));
		}
	}

	return dp[src][jump] = gems[src] + res;
}

int main()
{
	int n, d;

	cin>>n>>d;
	memset(dp, -1, sizeof(dp));

	for(int i=0; i<n; i++) {
		cin>>island;
		gems[island]++;
	}

	cout<<totalGems(d, d);

	return 0;

}
