/*
https://www.spoj.com/problems/CPRIME/
*/

#include <bits/stdc++.h>
using namespace std;

const long long MAX = 100000001;
int p[MAX];

void sieve() {
	long long i, j;

	p[0] = p[1] = 0;
	p[2] = 1;
	for(i=3; i<MAX; i+=2) {
		p[i] = 1;
	}

	for(i=3; i*i<MAX; i+=2) {
		if(p[i]) {
			for(j=i*i; j<MAX; j+=i) {
				p[j] = 0;
			}
		}
	}

	for(i=1; i<MAX; i++) {
		p[i] += p[i-1];
	}
}

void printError(long  x) {
	double res = 100.00 - 100.00*x/(p[x]*log(x));

	res = abs(res);
	printf("%.1f\n", res);
}

int main() {
	long n;

	sieve();
	while(true) {
		cin>>n;
		if(n==0) {
			break;
		}
		printError(n);
	}

	return 0;
}