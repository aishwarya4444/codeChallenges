/*
https://www.codechef.com/problems/DIVSET
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
#define INF 1e18
using namespace std;

vector<ll> nums;
int T, N, K, C;
int lo, mid, hi, X;

bool check(int L) {
	vector<ll> v[L];
	int i=0;

	for(auto num: nums) {
		if(v[i].size()==K) {
			break;
		}
		if(v[i].size()==0 || ( v[i].back()<INF/C && v[i].back()*C<=num)) {
			v[i].push_back(num);
			i = (i+1)%L;
		}
	}

	return v[L-1].size() == K;
}

int main() {

	ll num;

	si(T);

	while(T--) {
		si(N);
		si(K);
		si(C);

		nums.clear();
		while(N--) {
			sll(num);
			nums.push_back(num);
		}

		sort(nums.begin(), nums.end());

		X = 0;
		lo = 1;
		hi = nums.size()/K;

		while(lo<=hi) {
			mid = (lo+hi)/2;
			if(check(mid)) {
				X = mid;
				lo = mid+1;
			} else {
				hi = mid-1;
			}
		}

		printf("%d\n", X);
	}


	return 0;
}