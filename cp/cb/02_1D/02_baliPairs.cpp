/*

https://www.codechef.com/problems/JCWC02

College starts at eight in the morning! But Yash Jeswani is awake way before he is supposed to be.
It's a beautiful day for him until he realizes Yash Agarwal took his shoes and had been away while Jeswani was sleeping.
Jeswani is furious with such irresponsible behaviour.
Now, what to do then?
So he decides to go to "the Bali"'s shop to buy new shoes.
Now Bali shows him a N pairs of shoes.
But these shoes aren't some normal shoes!
These are "the Bali" shoes.
The size of left shoe will be always not equal to the size of the right shoe!
Being such close friends Bali agrees to gift him a pair of shoes if he answers his question.
Bali asks what are the total number of ways to select one shoe from each of the N pairs such that the summation of all the selected shoe sizes is odd?
Then do help Jeswani to get free shoes.
Since the answer can be too large print it modulo 10^9+7.

Input Format
First line contains N number of pairs N lines follows two space separated integer Li Ri representing shoe sizes

Constraints
1 ≤ N ≤ 10^5

1 ≤ Li,Ri ≤ 10^9

Li ≠ Ri

Output Format
Print number of ways to select one shoe from each of the N pairs such that the summation of the selected shoe sizes is odd. Since the answer can be too large print it modulo 10^9+7.

Sample Input
2
1 2
3 4
Sample Output
2
Explanation
The two ways are {1,4} and {2,3}.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9+7;
int n, l, r;
int p[100001][2];

// important thing to understand is that we do not need entire sum
// we just need to know if sum is odd or even
int dp[100001][2];

int solve(int pos, int sum) {
	if(pos==n) {
		// sum will be 0 or 1
		return sum;
	}

	if(dp[pos][sum] != -1) {
		return dp[pos][sum];
	}

	ll ans = 0;
	ans += solve(pos+1, (sum+p[pos][0])%2);
	ans += solve(pos+1, (sum+p[pos][1])%2);

	return dp[pos][sum] = ans%mod;
}

int main() {
	int t=1;

	// taking number of test cases for codechef problem
	// cin>>t;
	while(t--) {
		memset(dp, -1, sizeof dp);
		cin>>n;
		for(int i=0; i<n; i++) {
			cin>>l>>r;
			p[i][0] = l%2;
			p[i][1] = r%2;
		}
		cout<<solve(0, 0)<<endl;
	}

	return 0;
}

/*
// found below from tutorial video
// but did not understand much
#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int mod = 1e9+7;

int main() {
	int n, l, r, prod=1;

	cin>>n;
	cin>>l>>r;
	for(int i=1; i<n; i++) {
		cin>>l>>r;
		prod = (prod*2)%mod;
	}

	cout<<prod;

	return 0;
}
*/

/*
// TLE below solution
// important thing to understand is that we do not need entire sum
// we just need to know if sum is odd or even
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
int a[100001][2];
unordered_map<int, unordered_map<ll, int> > dp;
const int mod = 1e9+7;

int dfs(int i, ll sum) {
	if(i==n) {
		if(sum%2) return 1;
		else return 0;
	}

	if(dp.count(i) && dp[i].count(sum)) {
		return dp[i][sum];
	}

	int ways = 0;
	for(int j=0; j<2; j++) {
		ways += dfs(i+1, sum+a[i][j]);
		ways %= mod;
	}
	return dp[i][sum] = ways;
}

int main() {
	cin>>n;

	for(int i=0; i<n; i++) {
		cin>>a[i][0]>>a[i][1];
	}

	cout<<dfs(0, 0LL);


	return 0;
}
*/
