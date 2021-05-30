/*

https://cses.fi/problemset/task/1143

There are n hotels on a street. For each hotel you know the number of free rooms.
Your task is to assign hotel rooms for groups of tourists.
All members of a group want to stay in the same hotel.
The groups will come to you one after another, and you know for each group the number of rooms it requires.
You always assign a group to the first hotel having enough rooms.
After this, the number of free rooms in the hotel decreases.

Input
The first input line contains two integers n and m: the number of hotels and the number of groups.
The hotels are numbered 1,2,…,n.
The next line contains n integers h1,h2,…,hn: the number of free rooms in each hotel.
The last line contains m integers r1,r2,…,rm: the number of rooms each group requires.

Output
Print the assigned hotel for each group. If a group cannot be assigned a hotel, print 0 instead.

Constraints
1≤n,m≤2⋅105
1≤hi≤109
1≤ri≤109
Example

Input:
8 5
3 2 4 1 5 5 2 6
4 4 7 1 1

Output:
3 5 0 1 1
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> tree;
int N;

void query(int node, int group, int &room) {
	if(node >= 2*N || room != -1 || tree[node] < group) {
		return;
	}

	if(node >= N) {
		room = node;
		return;
	}

	if(group <= tree[2*node]) {
		query(2*node, group, room);
	} else {
		query(2*node+1, group, room);
	}
}

void update(int room, int group) {
	tree[room] -= group;
	for(int i=room/2; i>=1; i/=2) {
		tree[i] = max(tree[2*i], tree[2*i+1]);
	}
}

int main() {
	int n, m;

	cin>>n>>m;
	N = n;
	while(__builtin_popcount(N) != 1) {
		N++;
	}
	tree.assign(2*N, 0);
	for(int i=0; i<n; i++) {
		cin>>tree[N+i];
	}
	for(int i=N-1; i>=1; i--) {
		tree[i] = max(tree[2*i], tree[2*i+1]);
	}

	while(m--) {
		int group, room=-1;
		cin>>group;
		query(1, group, room);
		if(room != -1) {
			cout<<(room-(N-1))<<'\n';
			update(room, group);
		} else {
			cout<<0<<'\n';
		}
	}

	return 0;
}
