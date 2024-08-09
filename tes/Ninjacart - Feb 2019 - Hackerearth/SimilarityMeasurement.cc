#include<iostream>
#include<vector>
#define ULI unsigned long int
using namespace std;

void solveQ1(vector<ULI> &v, int pos, ULI val) {
  v[pos] = val;
}

void solveQ2(vector<ULI> &v, int pos) {
  int i=pos;
  while(i>0) {
    if(v[i-1]!=v[pos]) {
      cout<<i<<'\n';
      return;
    }
    i--;
  }
}

int main() {
	int q, pos, N, Q;
	ULI val;
	vector<ULI> v;
	v.push_back(0);
	cin >> N;
	while(N--) {
	  cin>>val;
	  v.push_back(val);
	}
	cin>>Q;
	while(Q--) {
	  cin>>q;
	  if(q==1) {
	    cin>>pos>>val;
	    solveQ1(v, pos, val);
	  } else {
	    cin>>pos;
	    solveQ2(v, pos);
	  }
	}
	return 0;
}