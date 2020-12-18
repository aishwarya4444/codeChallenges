/*
https://www.codechef.com/problems/DECREM
https://discuss.codechef.com/t/decrem-editorial/79704
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long T, L, R;

	cin>>T;

	while(T--) {
		cin>>L>>R;
		if(R < 2*L) {
			cout<<R<<'\n';
		} else {
			cout<<"-1\n";
		}
	}

	return 0;
}
