/*
Kadane's

input
10
-3 2 5 -1 6 3 -2 7 -5 2

output
20
*/

#include<bits/stdc++.h>
using namespace std;

int a[2000];

int main() {
	int n;

	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}

	int sum=0, maxSum=INT_MIN;
	for(int i=0; i<n; i++) {
		sum += a[i];
		if(sum < a[i]) sum = a[i];
		if(maxSum < sum) maxSum = sum;
	}

	cout<<maxSum;

	return 0;
}
