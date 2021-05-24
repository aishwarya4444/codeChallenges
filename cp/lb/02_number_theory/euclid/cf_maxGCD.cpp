/*
https://codeforces.com/problemset/problem/1370/A
https://codeforces.com/blog/entry/79107


Answer for any 𝑛≥2 is equal to ⌊𝑛2⌋ .

Solution:
Let the maximum gcd be equal to 𝑔.
Since the two numbers in a pair are distinct, one of them must be >𝑔 and both of them must be divisible by 𝑔.
The smallest multiple of 𝑔, greater than 𝑔, is 2⋅𝑔.
Since each number in the pair must be ≤𝑛, we must have 2⋅𝑔≤𝑛, or 𝑔≤⌊𝑛2⌋.
We can achieve 𝑔=⌊𝑛2⌋, by choosing ⌊𝑛2⌋ and 2⋅⌊𝑛2⌋.

Time Complexity: 𝑂(1)
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int t, n, ans;

	si(t);
	while(t--) {
		si(n);
		// commented code below gives TLE
		// ans = 1;
		// for(int a=1; a<n; a++) {
		// 	for(int b=a+1; b<=n; b++) {
		// 		ans = max(ans, __gcd(a,b));
		// 	}
		// }
		// cout<<ans<<'\n';
		cout<<n/2<<'\n';
	}

	return 0;
}
