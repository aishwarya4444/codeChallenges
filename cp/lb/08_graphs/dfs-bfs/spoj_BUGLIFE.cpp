/*
https://www.spoj.com/problems/BUGLIFE/

                # bipartite
                # dfs

*/

#include <bits/stdc++.h>
using namespace std;

#define NONE 'o'
#define MALE 'm'
#define FEMALE 'f'

vector<int> g[2001];
vector<char> gender(2001, NONE);
bool result;

void dfs(int id, char sex) {
	if(gender[id] == NONE) {
		gender[id] = sex;
		for(auto bug: g[id]) {
			if(sex == MALE) {
				dfs(bug, FEMALE);
			} else {
				dfs(bug, MALE);
			}
		}
	} else if(gender[id] != sex) {
		result = false;
	}
}

int main() {
	int t, T, bug, bugs, bug1, bug2;
	long interactions;

	cin>>T;

	for(t=1; t<=T; t++) {
		cin>>bugs>>interactions;

		for(bug=1; bug<=bugs; bug++) {
			g[bug].clear();
			gender[bug] = NONE;
		}

		while(interactions--) {
			cin>>bug1>>bug2;
			g[bug1].push_back(bug2);
			g[bug2].push_back(bug1);
		}

		cout<<"Scenario #"<<t<<":\n";
		result = true;

		for(bug=1; bug<=bugs; bug++) {
			if(result && gender[bug] == NONE) {
				dfs(bug, MALE);
			}
		}

		if(result) {
			cout<<"No suspicious bugs found!\n";
		} else {
			cout<<"Suspicious bugs found!\n";
		}

	}

	return 0;
}
