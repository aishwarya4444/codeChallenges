/*
https://www.codechef.com/problems/STACKS
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

vector<ll> nums;
int T, N;

int main() {

	ll num;

	si(T);

	while(T--) {
		si(N);

		nums.clear();
		while(N--) {
			sll(num);

			auto it = upper_bound(nums.begin(), nums.end(), num);
			if(it == nums.end()) {
				nums.push_back(num);
			} else {
				nums[it-nums.begin()] = num;
			}
		}

		printf("%d ", nums.size());
		for(auto val: nums) {
			printf("%lld ", val);
		}
		printf("\n");
	}


	return 0;
}