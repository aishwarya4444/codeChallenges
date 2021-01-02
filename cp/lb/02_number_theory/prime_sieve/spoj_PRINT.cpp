/*
https://www.spoj.com/problems/PRINT/
same as PRIME1
just use scanf and printf instead of cin and cout
*/

#include <bits/stdc++.h>
using namespace std;

const long long MAX = 2147483647;

vector<long long> primes;

void sieve(long long n) {
	long long i, j;
	bool p[n+1];

	p[0] = p[1] = false;
	p[2] = true;
	for(i=3; i<=n; i+=2) {
		p[i] = true;
	}

	for(i=3; i*i<=n; i+=2) {
		if(p[i]) {
			for(j=i*i; j<=n; j+= i) {
				p[j] = false;
			}
		}
	}

	for(i=2; i<=n; i++) {
		if(p[i]) {
			primes.push_back(i);
		}
	}
}

void segmented(long long l, long long r) {
	bool isPrime[r-l+1];
	long long i;

	for(i=0; i<r-l+1; i++) {
		isPrime[i] = true;
	}

	for(long long p : primes) {
		for(i=max(p*p, (p+l-1)/p*p); i<=r; i+=p) {
			isPrime[i-l] = false;
		}
	}

	if(l==1) {
		isPrime[0] = false;
	}

	for(i=0; i<r-l+1; i++) {
		if(isPrime[i]) {
			printf("%lld\n", i+l);
		}
	}

}

int main() {
	long long l, r;
	int t;

	sieve(floor(sqrt(MAX))+1);
	scanf("%d", &t);
	while(t--) {
		scanf("%lld", &l);
		scanf("%lld", &r);
		segmented(l, r);
	}

	return 0;
}
