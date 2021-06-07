/*
https://codeforces.com/problemset/problem/550/C

has DP solution also
https://codeforces.com/blog/entry/18329
*/

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	string s;
	int i, j, k, n, num;

	cin>>s;
	s = "00"+s;
	n = s.size();

	for(i=0; i<=n-3; i++) {
		for(j=i+1; j<=n-2; j++) {
			for(k=j+1; k<=n-1; k++) {
				num = 100*(s[i]-'0')+10*(s[j]-'0')+(s[k]-'0');
				if(num%8==0) {
					cout<<"YES\n"<<num;
					return 0;
				}
			}
		}
	}

	cout<<"NO";

	return 0;
}
