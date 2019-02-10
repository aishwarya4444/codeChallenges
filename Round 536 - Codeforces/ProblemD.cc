// http://codeforces.com/contest/1106/problem/D

#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;

map<int, set<int> > g;
vector<int> result;
vector<bool> visited;
priority_queue<int, vector<int>, greater<int> > q;

void dfs() {
  int node = 1;
  set<int>::iterator it;
  q.push(node);
  visited[node] = true;
  while(q.size()) {
    node = q.top();
    result.push_back(node);
    q.pop();
    for(it=g[node].begin(); it!=g[node].end(); it++) {
      if(!visited[*it]) {
        q.push(*it);
        visited[*it] = true;
      }
    }
  }
}

int main(void ) {
  int u, v, n, m, i;
  cin>>n>>m;
  for(i=0;i<m;i++) {
    cin>>u>>v;
    g[u].insert(v);
    g[v].insert(u);
  }
  visited.resize(n+1, false);
  dfs();
  for(i=0; i<n; i++) {
    cout<<result[i]<<' ';
  }
  cout<<endl;
  return 0;
}
