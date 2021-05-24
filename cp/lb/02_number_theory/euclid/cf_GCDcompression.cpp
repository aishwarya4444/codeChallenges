/*
https://codeforces.com/problemset/problem/1370/B
https://codeforces.com/blog/entry/79107
It is always possible to form 𝑛−1 pairs of elements such that their gcd is divisible by 2.
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	int t, n, num, i;
	vector<int> even, odd;
	vector<pair<int, int> > res;

	si(t);
	while(t--) {
		si(n);

		res.clear();
		even.clear();
		odd.clear();
		for(i=1; i<=2*n; i++) {
			cin>>num;
			if(num%2) {
				odd.push_back(i);
			} else {
				even.push_back(i);
			}
		}

		if(odd.size())
			for(i=0; i<odd.size()-1; i+=2) {
				res.push_back({odd[i], odd[i+1]});
			}

		if(even.size())
			for(i=0; i<even.size()-1; i+=2) {
				res.push_back({even[i], even[i+1]});
			}

		for(i=0; i<n-1; i++) {
			cout<<res[i].first<<' '<<res[i].second<<'\n';
		}
	}

	return 0;
}
