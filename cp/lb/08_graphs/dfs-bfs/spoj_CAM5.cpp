/*
https://www.spoj.com/problems/CAM5/

                # dfs
                # union find

*/

// dfs
#include <bits/stdc++.h>
using namespace std;

vector<int> g[100000];
vector<bool> person(100000, false);

void dfs(int id) {
	if(person[id]) {
		return;
	}
	person[id] = true;
	for(auto p: g[id]) {
		dfs(p);
	}
}

int main() {
	int t, e, a, b;
	long count, n, N;

	cin>>t;

	while(t--) {
		count = 0;
		cin>>N;
		for(n=0; n<N; n++) {
			person[n] = false;
			g[n].clear();
		}

		cin>>e;
		while(e--) {
			cin>>a>>b;
			g[a].push_back(b);
			g[b].push_back(a);
		}

		for(n=0; n<N; n++) {
			if(person[n] == false) {
				count++;
				dfs(n);
			}
		}

		cout<<count<<endl;
	}

	return 0;
}


// union find
#include <bits/stdc++.h>
using namespace std;

vector<int> person(100000, 0);

int _find(int p) {
	if(person[p] == p) {
		return p;
	}
	return person[p] = _find(person[p]);
}

void _union(int a, int b) {
	int p1 = _find(a), p2 = _find(b);
	if(p1 == p2) {
		return;
	}
	person[p1] = p2;
}

int main() {
	int t, e, a, b;
	int count, n, N;

	cin>>t;

	while(t--) {
		count = 0;
		cin>>N;
		for(n=0; n<N; n++) {
			person[n] = n;
		}

		cin>>e;
		while(e--) {
			cin>>a>>b;
			_union(a, b);
		}

		for(n=0; n<N; n++) {
			if(person[n] == n) {
				count++;
			}
		}

		cout<<count<<endl;
	}

	return 0;
}
