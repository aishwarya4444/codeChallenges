/*
https://www.spoj.com/problems/ADAMONEY/
*/

#include<bits/stdc++.h>
using namespace std;

// f(n) = f(n-1) + 2f(n-2) +0f(n-3) + 5f(n-4) + f(n-5)
vector<vector<long> > t = {	{1,2,0,5,1},
							{1,0,0,0,0},
							{0,1,0,0,0},
							{0,0,1,0,0},
							{0,0,0,1,0}
						};
vector<long> f = vector<long>(5, 0);
long MOD = 1000000007;

vector<vector<long> > mul(vector<vector<long> > &m1, vector<vector<long> > &m2) {
	vector<vector<long> > res = vector<vector<long> >(5, vector<long>(5, 0));

	int a, b, c;
	for(a=0; a<5; a++) {
		for(b=0; b<5; b++) {
			for(c=0; c<5; c++) {
				res[a][b] = ( MOD + res[a][b]%MOD + (m1[a][c]*m2[c][b])%MOD )%MOD;
			}
		}
	}

	return res;
}

vector<vector<long> > pow(vector<vector<long> > &m, int N) {
	if(N == 1) {
		return m;
	}
	vector<vector<long> > tmp;
	if(N%2) {
		tmp = pow(m, N-1);
		return mul(m, tmp);
	}
	tmp = pow(m, N/2);
	return mul(tmp, tmp);
}

int main() {
	long i, fn, N, T;

	cin>>T;
	while(T--) {
		for(i=4; i>=0; i--) {
			cin>>f[i];
		}
		cin>>N;
		if(N < 5) {
			cout<<f[N]<<endl;
		} else {
			vector<vector<long> > tn = pow(t, N-4);
			for(i=0, fn=0; i<5; i++) {
				fn = (MOD + fn%MOD + (tn[0][i]*f[i])%MOD )%MOD;
			}
			cout<<fn<<endl;
		}
	}

	return 0;
}
