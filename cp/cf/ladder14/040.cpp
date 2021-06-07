/*
http://codeforces.com/contest/510/problem/C
*/

#include <bits/stdc++.h>

using namespace std;

unordered_map<int, vector<int> > g;
vector<int> indegree;
vector<string> names;
string order;
priority_queue<int, vector<int>, greater<int>> src;
int n;

int main() {

	string name, n1, n2;
	int i, u, v, len;
	bool foundRelation = true;

	cin>>n;

	indegree.assign(26, 0);

	for(i=1; i<=n; i++) {
		cin>>name;
		names.push_back(name);
	}

	for(i=1; i<n; i++) {
		n1 = names[i-1];
		n2 = names[i];
		len = min(n1.size(), n2.size());
		if(n1.substr(0, len)==n2.substr(0, len) && n1.size()>n2.size()) {
			foundRelation = false;
			break;
		}
		for(int j=0; j<len; j++) {
			u = n1[j]-'a';
			v = n2[j]-'a';
			if(u!=v) {
				indegree[v]++;
				g[u].push_back(v);
				break;
			}
		}
	}

	if(foundRelation) {
		for(i=0; i<26; i++) {
			if(indegree[i]==0) {
				src.push(i);
			}
		}
	}

	while(src.size()) {
		u = src.top();
		src.pop();

		order += (u+'a');
		for(int v: g[u]) {
			indegree[v]--;
			if(indegree[v]==0) {
				src.push(v);
			}
		}
	}

	if(order.size() != 26) {
		cout<<"Impossible";
	} else {
		cout<<order;
	}


	return 0;
}
