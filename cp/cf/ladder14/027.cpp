/*
https://codeforces.com/problemset/problem/264/A

In this problem, there are many simple algorithms which works in O(n).
One of them is following:
You should prepare 2 vectors.
If s[i] = 'l', you should push i to the first vector.
If s[i] = 'r', you should push i to the second vector.
Finally, you should print the integers in the second vector by default order.
Then, you should print the integers in the first vector in the reverse order.

This algorithm works because if Liss divides an interval into two intervals A and B and she enters A, she will never enter B.
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	int i;

	cin>>s;
	for(i=0; i<s.size(); i++) {
		if(s[i]=='r') {
			printf("%d\n", i+1);
		}
	}

	for(i=s.size()-1; i>=0; i--) {
		if(s[i]=='l') {
			printf("%d\n", i+1);
		}
	}

	return 0;
}