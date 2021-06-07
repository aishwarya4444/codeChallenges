/*
Apoorvaa has created an elevated roof. She wants to know how much water can she save during rain.

Given n non negative integers representing the elevation map where width of every bar is 1, Find the maximum water that she can save.

Explanation for the Sample input Testcase:
Elevation Map

So the total units of water she can save is 5 units

Input Format
First line contains an integer n. Second line contains n space separated integers representing the elevation map.

Constraints
1 <= N <= 10^6

Output Format
Print a single integer containing the maximum unit of waters she can save.

Sample Input
10
0 2 1 3 0 1 2 1 2 1
Sample Output
5
Explanation
Refer to the image for explanation. Count the number of cells having water in them.
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int h[1000001];
int lh[1000001];
int rh[1000001];

int main() {
	int n, maxH;
	ll sum = 0LL;

	cin>>n;

	for(int i=0; i<n; i++) {
		cin>>h[i];
	}

	maxH = h[0];
	for(int i=1; i<n; i++) {
		lh[i] = maxH;
		maxH = max(maxH, h[i]);
	}

	maxH = h[n-1];
	for(int i=n-2; i>=0; i--) {
		rh[i] = maxH;
		maxH = max(maxH, h[i]);
	}

	for(int i=1; i<=n-2; i++) {
		maxH = min(lh[i], rh[i]);
		if(maxH>h[i]) {
			sum += maxH-h[i];
		}
	}

	cout<<sum;

	return 0;
}
