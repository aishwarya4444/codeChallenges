/*
https://codeforces.com/problemset/problem/230/B

https://codeforces.com/blog/entry/5437
It can be shown that only squares of prime numbers are T-primes.
There are not too many of them — as many as there are prime numbers not greater than sqrt(10^12) = 10^6.
Precompute these numbers (using, for example, the sieve of Eratosthenes) and store them in an array or an std::set.
Then we can answer each query by simply checking whether the number in question is amongst the precomputed numbers.
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

const int MAX=1e6;
bool primes[MAX];

void preparePrimes() {

	primes[2] = true;
	for(ll i=3; i<MAX; i+=2) {
		primes[i] = true;
	}

	for(ll i=3; i*i<MAX; i+=2) {
		if(primes[i]) {
			for(ll j=i*i; j<MAX; j+=i) {
				primes[j] = false;
			}
		}
	}
}

int main() {
	int n;
	ll num;

	preparePrimes();

	si(n);
	while(n--) {
		cin>>num;
		if(num==(1ll)*(int)sqrt(num)*(int)sqrt(num) && primes[(int)sqrt(num)]) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
	}

	return 0;
}
