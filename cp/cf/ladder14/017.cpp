/*
https://codeforces.com/problemset/problem/160/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {

	vector<int> a;
	int n, count=0, total=0, sum=0;

	si(n);
	a.assign(n, 0);

	for(int &num: a) {
		cin>>num;
		sum += num;
	}

	sort(a.begin(), a.end(), greater<int>());

	for(int num: a) {
		total += num;
		count++;
		if(total*2 > sum) {
			cout<<count;
			break;
		}
	}

	return 0;
}
