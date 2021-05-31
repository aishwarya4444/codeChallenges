#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
C++ STL: Policy based data structures
https://codeforces.com/blog/entry/11080
https://opensource.apple.com/source/llvmgcc42/llvmgcc42-2336.9/libstdc++-v3/testsuite/ext/pb_ds/example/
https://opensource.apple.com/source/llvmgcc42/llvmgcc42-2336.9/libstdc++-v3/testsuite/ext/pb_ds/example/tree_order_statistics.cc.auto.html
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
oset<pair<int, int>> s;
int p[200000];

int qry(int x) {
	return s.order_of_key({x, 0});
}

int main() {
	int n, q;
	cin>>n>>q;

	for(int i=0; i<n ; i++) {
		cin>>p[i];
		s.insert({p[i], i});
	}

	for(int i=0; i<q; i++) {
		char qt;
		cin>>qt;
		if(qt=='!') {
			int k, x;
			cin>>k>>x;
			k--;
			s.erase({p[k], k});
			p[k] = x;
			s.insert({p[k], k});
		} else {
			int a, b;
			cin>>a>>b;
			cout<<qry(b+1)-qry(a)<<'\n';
		}
	}


	return 0;
}
