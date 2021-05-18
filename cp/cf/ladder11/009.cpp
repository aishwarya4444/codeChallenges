/*
https://codeforces.com/problemset/problem/110/A
*/

#include <bits/stdc++.h>
#define si(n) scanf("%d", &n)
#define sll(n) scanf("%lld", &n)
#define ll long long
using namespace std;

int main() {
	string s;
	int lucky=0;

	cin>>s;


	for(auto ch: s) {
		switch(ch-'0') {
			case 4:
				lucky++;
				break;
			case 7:
				lucky++;
				break;
			default:
				break;
		}
		if(lucky > 7) {
			break;
		}
	}

	if(lucky!=7 && lucky!=4) {
		cout<<"NO";
	} else {
		cout<<"YES";
	}

	return 0;
}
