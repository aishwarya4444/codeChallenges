/*
https://www.spoj.com/problems/DAGCNT2/
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 20001;

vector<int> gr[N];  // graph
vector<int> order;  // topological sort order
int w[N];           // weights
int id[N];          // indegree of nodes
bitset<N> reach[N]; // short representation of reachability 2D matrix
int n, m, t;

void topologicalSort() {
  queue<int> src;

  for(int i=1; i<=n; i++) {
    if(id[i] == 0) {
      src.push(i);
    }
  }

  while(src.size()) {
    int u = src.front();
    src.pop();

    order.push_back(u);

    for(int v: gr[u]) {
      id[v]--;
      if(id[v] == 0) {
        src.push(v);
      }
    }
  }

}

void reset() {
  order.clear();
  for(int i=1; i<=n; i++) {
    id[i] = 0;
    gr[i].clear();
    reach[i].reset();
  }
}

void solve() {
  topologicalSort();

  for(int i=order.size()-1; i>=0; i--) {
    int start = order[i];
    reach[start].set(start);
    for(int end: gr[start]) {
      reach[start] |= reach[end];
    }
  }

  for(int i=1; i<=n; i++) {
    int ans = 0;
    for(int j=1; j<=n; j++) {
      if(reach[i][j]) {
        ans += w[j];
      }
    }
    // cout<<ans<<' ';
    printf("%d ", ans);
  }
  // cout<<endl;
  printf("\n");
}

int main(){
  ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  // cin>>t;
  scanf("%d", &t);

  while(t--) {
    // cin>>n>>m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++) {
      // cin>>w[i];
      scanf("%d", &w[i]);
    }

    for(int i=1; i<=m; i++) {
      int u, v;
      // cin>>u>>v;
      scanf("%d %d", &u, &v);
      gr[u].push_back(v);
      id[v]++;
    }

    solve();

    reset();
  }
}