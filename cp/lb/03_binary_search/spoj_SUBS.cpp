/*
https://www.spoj.com/problems/SUBS/

https://codinghangover.wordpress.com/2013/12/11/spoj-subs-string-it-out/
https://gist.github.com/vishnujayvel/7907760


find K so that X^K is subsequence of Y
K can be found using binary search
*/

#include <bits/stdc++.h>
using namespace std;


int T, K, NX, NY;
string X, Y, Xk;

bool isSubsequence()  {
	// check if Xk is subsequence of Y
	int j = 0;
	for(int i=0; i<NY; i++) {
		if(Y[i] == Xk[j]) {
			j++;
		}
	}
	return j==Xk.size();;
}

void make_Xk(int K) {
	Xk = "";
	for(int n=0; n<NX; n++) {
		Xk += string(K, X[n]);
	}
}

void search(int lo, int hi) {
	int mid, K=0;

	while(lo<=hi) {
		mid = (lo+hi)/2;
		make_Xk(mid);
		if(isSubsequence()) {
			K = mid;
			lo = mid+1;
		} else {
			hi = mid-1;
		}
	}

	cout<<K<<endl;
}

int main() {

	cin>>T;

	while(T--) {
		cin>>X>>Y;
		NX = X.size();
		NY = Y.size();
		search(0, NY/NX);
	}

	return 0;
}