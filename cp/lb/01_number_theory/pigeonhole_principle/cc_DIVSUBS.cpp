/*
https://www.codechef.com/problems/DIVSUBS
https://brilliant.org/wiki/pigeonhole-principle-definition/#
https://www.geeksforgeeks.org/find-a-non-empty-subset-in-an-array-of-n-integers-such-that-sum-of-elements-of-subset-is-divisible-by-n/
https://codeforces.com/blog/entry/80683
*/

#include<bits/stdc++.h>
using namespace std;
#define vl vector<long>

int main()
{
	long i, n, N, T;
	vl f;
	bool found;
	unordered_map<long, long> m;

	cin>>T;
	while(T--) {
		cin>>N;
		f = vl(N+1, 0);
		found = false;
		m.clear();

		for(n=1; n<=N; n++) {
			cin>>f[n];
			f[n] = (f[n]+f[n-1])%N;
		}

		for(n=1; n<=N; n++) {
			if(m[f[n]] || f[n]==0) {
				found = true;
				break;
			}
			m[f[n]] = n;
		}

		if(found) {
			cout<<n-m[f[n]]<<endl;
			for(i=m[f[n]]+1; i<=n; i++) {
				cout<<i<<" ";
			}
			cout<<endl;
		} else {
			cout<<"-1\n";
		}
	}

	return 0;
}
