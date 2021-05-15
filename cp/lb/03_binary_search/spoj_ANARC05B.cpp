/*
https://www.spoj.com/problems/ANARC05B/

O(N) solution
https://www.youtube.com/watch?v=w-6YHcGmSxM


dp + binary
https://github.com/ashutosh1598/SPOJ/blob/master/anarc05b.cpp
*/

#include <bits/stdc++.h>
using namespace std;

int n1, n2, N1, N2;
int s1[10000], s2[10000];
int sum1, sum2, maxSum;


int main() {

	while(true) {
		cin>>N1;
		if(N1==0) {
			break;
		}

		for(int n=0; n<N1; n++) {
			cin>>s1[n];
		}

		cin>>N2;
		for(int n=0; n<N2; n++) {
			cin>>s2[n];
		}

		n1 = 0;
		n2 = 0;
		sum1 = 0;
		sum2 = 0;
		maxSum = 0;
		while(n1<N1 && n2<N2) {
			if(s1[n1] < s2[n2]) {
				sum1 += s1[n1];
				n1++;
			} else if(s2[n2] < s1[n1]) {
				sum2 += s2[n2];
				n2++;
			} else {
				maxSum += max(sum1, sum2) + s1[n1];
				n1++;
				n2++;
				sum1 = 0;
				sum2 = 0;
			}
		}

		while(n1<N1) {
			sum1 += s1[n1];
			n1++;
		}

		while(n2<N2) {
			sum2 += s2[n2];
			n2++;
		}

		maxSum += max(sum1, sum2);

		cout<<maxSum<<endl;

	}

	return 0;
}