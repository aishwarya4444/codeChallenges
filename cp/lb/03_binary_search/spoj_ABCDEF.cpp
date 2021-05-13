/*
https://www.spoj.com/problems/ABCDEF/

(a*b)+c
-------   -  e = f
  d


(a*b)+c = d*(e+f) ... where d!=0
*/

#include <bits/stdc++.h>
using namespace std;

int main() {

	int N, S[100], total=0;
	vector<int> left, right;

	cin >> N;

	for(int n=0; n<N; n++) {
		cin>>S[n];
	}

	for(int a=0; a<N; a++) {
		for(int b=0; b<N; b++) {
			for(int c=0; c<N; c++) {
				left.push_back((S[a]*S[b])+S[c]);
			}
		}
	}

	for(int d=0; d<N; d++) {
		for(int e=0; e<N; e++) {
			for(int f=0; f<N; f++) {
				if(S[d]!=0) {
					right.push_back(S[d]*(S[e]+S[f]));
				}
			}
		}
	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	for(int num: left) {
		int lo = lower_bound(right.begin(), right.end(), num) - right.begin();
		int hi = upper_bound(right.begin(), right.end(), num) - right.begin();
		total += hi-lo;
	}

	cout<<total;

	return 0;
}


/*

// another working solution

#include <bits/stdc++.h>
using namespace std;

int main() {

	int N, S[100], total=0;
	vector<int> left, right;

	cin >> N;

	for(int n=0; n<N; n++) {
		cin>>S[n];
	}

	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			for(int k=0; k<N; k++) {
				left.push_back((S[i]*S[j])+S[k]);
				if(S[i]!=0) {
					right.push_back(S[i]*(S[j]+S[k]));
				}
			}
		}
	}

	sort(right.begin(), right.end());

	for(int num: left) {
		pair<vector<int>::iterator, vector<int>::iterator > bound;
		bound = equal_range(right.begin(), right.end(), num);
		// int lo = lower_bound(right.begin(), right.end(), num) - right.begin();
		// int hi = upper_bound(right.begin(), right.end(), num) - right.begin();
		int lo = bound.first-right.begin();
		int hi = bound.second-right.begin();
		total += hi-lo;
	}

	cout<<total;

	return 0;
}

*/
