/*
https://codeforces.com/problemset/problem/116/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int n, a, b, sum=0, res=0;

	si(n);

	while(n--) {
		si(a);
		si(b);
		sum += b-a;
		res = max(res, sum);
	}

	cout<<res;

	return 0;
}
