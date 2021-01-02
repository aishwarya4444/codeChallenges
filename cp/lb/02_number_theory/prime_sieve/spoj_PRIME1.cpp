/*
https://www.spoj.com/problems/PRIME1/
https://www.youtube.com/watch?v=fByR5N-TseY
https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html

        # segmented sieve
        # primality test
*/

// segmented sieve solution
#include <bits/stdc++.h>
using namespace std;

const long long MAX = pow(10, 9);

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
			cout<<i+l<<endl;
		}
	}

	cout<<endl;

}

int main() {
	long long l, r;
	int t;

	sieve(floor(sqrt(MAX))+1);
	cin>>t;
	while(t--) {
		cin>>l>>r;
		segmented(l, r);
	}

	return 0;
}


// primality test solution
#include<iostream>
using namespace std;
typedef unsigned long long int ULLI;

// http://en.wikipedia.org/wiki/Primality_test

bool primalityTest(ULLI i)
{
    if(i==1)return false;
	if(i==2 || i==3)return true;
	if(i%2==0 || i%3==0)return false;
	for(ULLI j=5;j*j<=i;j+=6)
	{
	    if(i%(j)==0 || i%(j+2)==0)return false;
	}
	return true;
}

int main( void)
{
    ULLI t, i, l, r;
	cin>>t;
	while(t--)
    {
        cin>>l>>r;;
        for(i=l;i<=r;i++)
		{
		    if(primalityTest(i))cout<<i<<'\n';
	    }
		cout<<endl;
    }
    return 0;
}
