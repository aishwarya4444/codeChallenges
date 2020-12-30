/*
https://www.spoj.com/problems/ELEVTRBL/

        #bfs
*/

#include <bits/stdc++.h>
using namespace std;

int f, s, g, u, d;
unordered_set<int> visited;

bool isInsideRange(int floor) {
	return floor>=1 && floor<=f;
}

void bfs() {
	queue<int> q;
	int level=0, N, floor;

	q.push(s);
	while(q.size()) {
		N = q.size();
		while(N--) {
			floor = q.front();
			q.pop();

			if(visited.count(floor)) {
				continue;
			}
			visited.insert(floor);

			if(floor == g) {
				cout<<level<<endl;
				return;
			}

			if(isInsideRange(floor+u)) {
				q.push(floor+u);
			}
			if(isInsideRange(floor-d)) {
				q.push(floor-d);
			}
		}
		level++;
	}

	cout<<"use the stairs\n";
	return;
}

int main() {
	cin>>f>>s>>g>>u>>d;
	bfs();
	return 0;
}
