/*
https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/practice-problems/algorithm/gcd-on-directed-graph-1122228a/
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 100001;
int n;                      // number of nodes
int m;                      // number of edges
int col;                    // color
vector<int> gr[N];          // graph
vector<int> rg[N];          // reverse graph
unordered_set<int> dag[N];  // DAG
int c[N];                   // cost
int id[N];                  // indegree
int color[N];               // representative color
int gcd[N];                 // GCD of representative array
bool visited[N];            // visited
stack<int> st;              // order of dfs1
unordered_set<int> dp[N];
int ans = INT_MAX;

void dfs1(int u) {
  visited[u] = true;

  for(int v: gr[u]) {
    if(!visited[v]) {
      dfs1(v);
    }
  }

  st.push(u);
}

void dfs2(int u, int col) {
  visited[u] = true;
  color[u] = col;
  gcd[col] = __gcd(gcd[col], c[u]);

  for(int v: rg[u]) {
    if(!visited[v]) {
      dfs2(v, col);
    }
  }
}

void kosaraju() {
  for(int i=1; i<=n; i++) {
    if(!visited[i]) {
      dfs1(i);
    }
  }

  memset(visited, false, sizeof visited);

  col = 0;
  while(st.size()) {
    int node = st.top();
    st.pop();

    if(!visited[node]) {
      col++;
      dfs2(node, col);
    }
  }
}

void makeDAG() {
  for(int u=1; u<=n; u++) {
    for(int v: gr[u]) {
      if(color[u]!=color[v] && dag[color[u]].count(color[v])==0) {
        dag[color[u]].insert(color[v]);
        id[color[v]]++;
      }
    }
  }
}

void topologicalSort() {
  queue<int> q;

  for(int i=1; i<=col; i++) {
    if(id[i] == 0) {
      q.push(i);
      dp[i].insert(gcd[i]);
      ans = min(ans, gcd[i]);
    }
  }

  while(q.size()) {
    int u = q.front();
    q.pop();

    for(int v: dag[u]) {
      for(int g: dp[u]) {
        int val = __gcd(g, gcd[v]);
        dp[v].insert(val);
        ans = min(ans, val);
        if(ans == 1) {
          cout<<ans;
          exit(0);
        }
      }
      id[v]--;
      if(id[v] == 0) {
        q.push(v);
      }
    }
  }
}

int main(){
  int u, v;
  cin>>n>>m;

  for(int i=1; i<=n; i++) {
    cin>>c[i];
  }

  for(int i=1; i<=m; i++) {
    cin>>u>>v;
    gr[u].push_back(v);
    rg[v].push_back(u);
  }

  kosaraju();
  makeDAG();
  topologicalSort();

  cout<<ans;

  return 0;

}
