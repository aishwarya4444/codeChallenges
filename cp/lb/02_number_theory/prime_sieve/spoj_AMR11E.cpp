/*
https://www.spoj.com/problems/AMR11E/
https://www.geeksforgeeks.org/nth-smart-number/
https://github.com/AliOsm/CompetitiveProgramming/blob/master/SPOJ/AMR11E%20-%20Distinct%20Primes.cpp
*/

#include <bits/stdc++.h>
using namespace std;

// MAX should be big, I got WA for MAX = 10000
const long long MAX = 10000000;

bitset<MAX> p;
int lookup[MAX];
vector<long long> lucky;

void sieve() {
	long long i, j;

	p.set();
	p[0] = p[1] = 0;

	for(i=2; i*i<MAX; i++) {
		if(p[i]) {
			for(j=2*i; j<MAX; j+=i) {
				p[j] = 0;
				++lookup[j];
			}
		}
	}

	for(i=0; i<MAX; i++) {
		if(lookup[i]>=3) {
			lucky.push_back(i);
		}
	}
}



int main() {
	int n, T;

	sieve();
	cin>>T;
	while(T--) {
		cin>>n;
		cout<<lucky[n-1]<<endl;
	}

	return 0;
}
