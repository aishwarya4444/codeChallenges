/*
https://www.codechef.com/problems/LOWSUM
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

vector<ll> A, B, sums;
priority_queue<ll> pq;
ll val;
int T, K, Q, q;

int main() {

	si(T);
	while(T--) {
		A.clear();
		B.clear();
		sums.clear();

		si(K);
		si(Q);

		for(int k=0; k<K; k++) {
			sll(val);
			A.push_back(val);
		}

		for(int k=0; k<K; k++) {
			sll(val);
			B.push_back(val);
		}

		sort(A.begin(), A.end());
		sort(B.begin(), B.end());

		for(auto a: A) {
			for(auto b: B) {
				if(pq.size() < 10000) {
					pq.push(a+b);
				} else if(a+b < pq.top()) {
					pq.pop();
					pq.push(a+b);
				} else {
					break;
				}
			}
		}

		while(pq.size()) {
			sums.insert(sums.begin(), pq.top());
			pq.pop();
		}

		while(Q--) {
			si(q);
			cout<<sums[q-1]<<'\n';
		}
	}


	return 0;
}