/*
https://codeforces.com/problemset/problem/363/B
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int n, k, i, idx, num, sum=0, minSum;
	queue<int> q;

	si(n);
	si(k);

	for(i=1; i<=k; i++) {
		si(num);
		q.push(num);
		sum += num;
	}

	minSum = sum;
	idx = 1;
	for(i=k+1; i<=n; i++) {
		si(num);
		q.push(num);
		sum -= q.front();
		q.pop();
		sum += num;
		if(sum<minSum) {
			minSum = sum;
			idx = i-(k-1);
		}
	}

	cout<<idx;

	return 0;
}
