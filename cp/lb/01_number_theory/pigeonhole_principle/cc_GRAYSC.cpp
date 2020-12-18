/*
https://www.codechef.com/problems/GRAYSC
https://discuss.codechef.com/t/graysc-editorial/388
*/

#include<bits/stdc++.h>
using namespace std;
#define vull vector<unsigned long long>

int main()
{
	long a, b, c, d, n, N;
	vull f;

	cin>>N;

	if(N >= 130) {
		cout<<"Yes\n";
		return 0;
	}

	f = vull(N, 0);
	for(n=0; n<N; n++) {
		cin>>f[n];
	}

	for(a=0; a<N; a++) {
		for(b=a+1; b<N; b++) {
			for(c=b+1; c<N; c++) {
				for(d=c+1; d<N; d++) {
					if((f[a]^f[b]^f[c]^f[d]) == 0) {
						cout<<"Yes\n";
						return 0;
					}
				}
			}
		}
	}

	cout<<"No\n";

	return 0;
}

