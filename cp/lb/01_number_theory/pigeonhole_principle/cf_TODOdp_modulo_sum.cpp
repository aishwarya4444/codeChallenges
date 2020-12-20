/*
https://codeforces.com/problemset/problem/577/B
https://codeforces.com/blog/entry/20226

Two Cases:
    [1] Prefix sum can be used only if MOD < N. In this problem we don't have to print indexes or values. So, this part also becomes simpler.
    [2] For MOD >= N , we have to use DP or set
*/


// set solution
#include<bits/stdc++.h>
using namespace std;

int main()
{
	long n, m, i, num;
	unordered_set<long> s, _s;

	cin>>n>>m;

	if(m < n) {
		cout<<"YES\n";
		return 0;
	}

	s.insert(0);
	for(i=1; i<=n; i++) {
		cin>>num;
		_s = s;
		for(auto val: s) {
			if((val+num)%m == 0) {
				cout<<"YES\n";
				return 0;
			}
			_s.insert((val+num)%m);
		}
		s = _s;
	}

	cout<<"NO\n";


	return 0;
}

// dp solution
#include<bits/stdc++.h>
using namespace std;
int dp[1001][1001]={};
int main(){
	int n, m;
	cin>> n>> m;
	int arr[n+1];
	for(int i=1 ;i<=n ;i++ )
	    cin>> arr[i];
	if(n > m)
		return cout<< "YES"<< endl, 0;
	else
		for(int i=1 ;i<=n ;i++ )
			for(int j=0 ;j<m ;j++ ) {
				dp[i][j]=dp[i-1][j] | dp[i-1][(j-arr[i]%m+m)%m];
				dp[i][arr[i]%m]=1;
			}
	if(dp[n][0])
	    return cout<< "YES"<< endl, 0 ;
	cout<< "NO"<< endl;
}
