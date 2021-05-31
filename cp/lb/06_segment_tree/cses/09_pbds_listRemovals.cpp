#include <bits/stdc++.h>
#define ll long long
#define ar array
using namespace std;

/*
C++ STL: Policy based data structures
https://codeforces.com/blog/entry/11080
*/

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	int n;
	// oset<ar<int, 2>> s;
	oset<pair<int, int>> s;
	cin>>n;

	for(int i=0; i<n ; i++) {
		int x;
		cin>>x;
		s.insert({i, x});
	}

	for(int i=0; i<n; i++) {
		int p;
		cin>>p, --p;
		auto it = s.find_by_order(p);
		// cout<<(*it)[1]<<' ';
		cout<<(*it).second<<' ';
		s.erase(it);
	}


	return 0;
}
