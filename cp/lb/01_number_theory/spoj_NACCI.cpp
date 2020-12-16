/*
https://www.spoj.com/problems/NACCI/
*/

#include<bits/stdc++.h>
#define vvl vector<vector<long> >
#define vl vector<long>
using namespace std;



vvl t = vvl(30, vl(30, 0));
vl f = vl(30, 0);
long T, N, K, L, MOD;

vvl multiply(vvl &m1, vvl &m2) {
	vvl m3 = vvl(N, vl(N, 0) ) ;

	int i, j, k;

	for(i=0; i<N; i++) {
		for(j=0; j<N; j++) {
			for(k=0; k<N; k++) {
				m3[i][j] = (m3[i][j] + MOD + m1[i][k]*m2[k][j]%MOD ) % MOD;
			}
		}
	}

	return m3;
}

vvl power(vvl &m, long p) {
	if(p <= 1) {
		return m;
	}

	vvl tmp;
	if(p%2) {
		tmp = power(m, p-1);
		return multiply(m, tmp);
	}

	tmp = power(m, p/2);
	return multiply(tmp, tmp);
}

void getTerm(long n) {
	if(n<N) {
		cout<<f[N-1-n]<<endl;
		return;
	}
	vvl tn = power(t, n - (N-1));
	long i, sum = 0;
	for(i=0; i<N; i++) {
		sum = ( sum + MOD + f[i]*tn[0][i]%MOD ) % MOD;
	}

	cout<<sum<<endl;

}

int main()
{
	long i, r, c;
	cin>>T;
	while(T--)
	{
	 cin>>N>>K>>L;

	 MOD = (long)pow(10, K);
	 // f = vl(N, 0);
	 // t = vvl(N, vl(N, 0));

	 for(i=N-1; i>=0; i--) {
	 	f[i] = N-1 - i;
	 }

	 for(r=0; r<N; r++) {
	 	for(c=0; c<N; c++) {
	 		if(r==0) {
	 			t[r][c] = 1;
	 		} else {
	 			t[r][c] = 0;
	 		}
	 	}
	 	if(r) {
	 		t[r][r-1] = 1;
	 	}
	 }

	 getTerm(L);
	}
  return 0;
}
