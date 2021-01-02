/*
https://www.spoj.com/problems/TDPRIMES/
*/

#include <bits/stdc++.h>
using namespace std;

const long long MAX = pow(10, 8)+1;
bool p[MAX];
vector<long long> res;

void sieve() {
	int i, j;

	for(i=3; i<MAX; i+=2) {
		p[i] = true;
	}
	p[0] = p[1] = false;
	p[2] = true;

	for(i=3; i*i<MAX; i+=2) {
		if(p[i]) {
			for(j=i*i; j<MAX; j+= i) {
				p[j] = false;
			}
		}
	}

	for(i=2; i<MAX; i++) {
		if(p[i]) {
			res.push_back(i);
		}
	}
}

void printResult() {
	int i;
	for(i=0; i<res.size(); i+=100) {
		cout<<res[i]<<endl;
	}
}

int main() {

	sieve();
	printResult();

	return 0;
}
