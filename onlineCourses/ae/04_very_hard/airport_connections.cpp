#include <vector>
#include <unordered_map>
#include <stack>
#include <cstring>
using namespace std;

/*
https://www.geeksforgeeks.org/strongly-connected-components/
https://www.geeksforgeeks.org/connectivity-in-a-directed-graph/
https://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
https://cp-algorithms.com/graph/strongly-connected-components.html
https://www.youtube.com/watch?v=qz9tKlF431k
*/

unordered_map<string, int> aid;
unordered_map<int, vector<int>> graph;
unordered_map<int, vector<int>> rgraph;
vector<int> representative, indegree;
vector<bool> visited;
stack<int> st;
int A;

void dfs1(int u) {
	visited[u] = true;
	for(int v: graph[u]) {
		if(visited[v]==false) {
			dfs1(v);
		}
	}
	st.push(u);
}

void dfs2(int u, int rep) {
	visited[u] = true;
	representative[u] = rep;
	for(int v: rgraph[u]) {
		if(visited[v]==false) {
			dfs2(v, rep);
		}
	}
}

int airportConnections(vector<string> airports, vector<vector<string>> routes,
                       string startingAirport) {
  // Write your code here.
	int count=0, u, v;

	A = airports.size();
	visited = vector<bool>(A, false);
	representative = vector<int>(A, 0);
	indegree = vector<int>(A, 0);
	graph.clear();
	rgraph.clear();

	for(auto airport: airports) {
		aid[airport] = count++;
	}

	for(auto route: routes) {
		u = aid[route[0]];
		v = aid[route[1]];
		graph[u].push_back(v);
		rgraph[v].push_back(u);
	}

	for(u=0; u<A; u++) {
		if(visited[u]==false) {
			dfs1(u);
		}
	}

	visited = vector<bool>(A, false);
	while(st.size()) {
		u = st.top();
		st.pop();
		if(visited[u]==false) {
			dfs2(u, u);
		}
	}

	for(auto entry: graph) {
		u = entry.first;
		for(int v: entry.second) {
			if(representative[u] != representative[v]) {
				indegree[representative[v]]++;
			}
		}
	}

	u = aid[startingAirport];
	count = 0;
	for(v=0; v<A; v++) {
		if(indegree[v]==0 && v!=representative[u] && v==representative[v]) {
			count++;
		}
	}

  return count;
}
