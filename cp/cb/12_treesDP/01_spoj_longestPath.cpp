/*
https://www.spoj.com/problems/PT07Z/

[1] using 2 dfs
[2] using 2 bfs
[3] using dp - dfs without visited
[4] using dp - dfs with visited
*/



/*
use 2 dfs
https://www.youtube.com/watch?v=x5ZH4pnts7Q
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> tree[10001];
bool visited[10001];
int maxD, maxNode;
int n;

void dfs(int u, int d) {
    visited[u] = true;

    if(d >= maxD) {
        maxD = d;
        maxNode = u;
    }

    for(int v: tree[u]) {
        if(!visited[v]) {
            dfs(v, d+1);
        }
    }
}

int main() {
    int u, v;

    cin>>n;
    for(int i=1; i<n; i++) {
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    maxD = 0;
    memset(visited, false, sizeof visited);
    dfs(1, 0);

    memset(visited, false, sizeof visited);
    dfs(maxNode, 0);

    cout<<maxD;

    return 0;
}



/*
using 2 bfs
*/
#include <bits/stdc++.h>
using namespace std;

#define MAX 10000

vector<int> g[1+MAX];
vector<bool> visited;

pair<int, int> bfs(int u) {
	queue<int> q;
	int level = 0, L;

	visited = vector<bool>(1+MAX, false);
	q.push(u);
	while(q.size()) {
		L = q.size();
		level++;
		while(L--) {
			u = q.front();
			q.pop();
			if(visited[u]) {
				continue;
			}
			visited[u] = true;
			for(auto v: g[u]) {
				if(visited[v]) {
					continue;
				}
				q.push(v);
			}
		}
	}

	return make_pair(u, level-1);
}

int main() {
	int u, v, n, N, L, level;
	queue<int> q;

	cin>>N;

	for(n=1; n<N; n++) {
		cin>>u>>v;

		g[u].push_back(v);
		g[v].push_back(u);
	}

	cout<<bfs(bfs(1).first).second<<endl;

	return 0;
}




/*
use dp - dfs(node, parent)
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> tree[10001];
// max depth possible from each node
int depth[10001];
// longest path = diameter
int dia;
int n;

void dfs(int u, int par) {
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for(int v: tree[u]) {
        if(v != par) {
            dfs(v, u);
            minHeap.push(depth[v]+1);
            if(minHeap.size() > 2) {
                minHeap.pop();
            }
        }
    }

    int depth1 = 0, depth2 = 0;

    if(minHeap.size()) {
        depth1 = minHeap.top();
        minHeap.pop();
    }

    if(minHeap.size()) {
        depth2 = minHeap.top();
        minHeap.pop();
    }

    depth[u] = max(depth1, depth2);
    dia = max(dia, depth1+depth2);
}

int main() {
    int u, v;

    cin>>n;
    for(int i=1; i<n; i++) {
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    memset(depth, 0, sizeof depth);
    dfs(1, 0);

    cout<<dia;

    return 0;
}





/* using dp - dfs(node) and visited */
#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<int> tree[10001];
int dist[10001];
bool visited[10001];
int ans;
int n;

void dfs(int u) {
    visited[u] = true;

    priority_queue<int, vector<int>, greater<int> > minHeap;

    for(int v: tree[u]) {
        if(!visited[v]) {
            dfs(v);
            minHeap.push(dist[v]+1);
            if(minHeap.size() > 2) {
                minHeap.pop();
            }
        }
    }

    int max1 = 0, max2 = 0;

    if(minHeap.size()) {
        max1 = minHeap.top();
        minHeap.pop();
    }

    if(minHeap.size()) {
        max2 = minHeap.top();
        minHeap.pop();
    }

    dist[u] = max(max1, max2);;
    ans = max(ans, max1+max2);
}

int main() {
    int u, v;

    cin>>n;
    for(int i=1; i<n; i++) {
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1);

    cout<<ans;

    return 0;
}
