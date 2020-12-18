/*
https://www.spoj.com/problems/HALLOW/
https://codeforces.com/blog/entry/60485
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long c, n, i;
	vector<long> f;
	unordered_map<long, long> m;

	while(true) {
		cin>>c>>n;

		if(c==0) {
			break;
		}

		m.clear();
		f.clear();
		f = vector<long>(n+1, 0);
		for(i=1; i<=n; i++) {
			cin>>f[i];
			f[i] = (f[i] + f[i-1])%c;
		}

		for(i=1; i<=n; i++) {
		    /*
		    Check for following conditions:
		        [1] remainder of sum upto f[i] is 0
		        [2] remainder of sum upto f[i] has occurred twice
		    */
			if(f[i]==0 || m.find(f[i])!=m.end()) {
				break;
			}
			m[f[i]] = i;
		}

		for(n=m[f[i]]+1; n<=i; n++) {
			cout<<n<<' ';
		}
		cout<<'\n';
		// "no sweets" will not happen because c<=n
	}

	return 0;
}
