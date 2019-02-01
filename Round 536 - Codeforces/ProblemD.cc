// http://codeforces.com/contest/1106/problem/D

#include<iostream>
#include<vector>
using namespace std;

int g[100001][100001];

void init_g(int n) {
  int r, c;
  for(r=0;r<=n;r++) {
    for(c=0;c<=n;c++) {
      g[r][c] = 0;
    }
  }
}

void solve(vector<int> path, vector<bool> &visited, int N, vector<int> &result) {
  int i, lastVisitedNode = path[path.size()-1];
  string a="", b="";
  if(lastVisitedNode == N) {
    if(result.size() == 0) {
      result = path;
      return;
    }
    for(i=0;i<N;i++) {
      a += to_string(path[i]);
      b += to_string(result[i]);
    }cout<<a<<endl<<b<<endl;
    if(a<b) {
      result = path;
    }
    return;
  }cout<<endl;
  for(i=1;i<=N;i++) {
    if(g[lastVisitedNode][i] && !visited[i]) {
      visited[i] = true;
      path.push_back(i);
      solve(path, visited, N, result);
      path.pop_back();
      visited[i] = false;
    }
  }
}

int main(void ) {
  int r, c, n, m, i;
  vector<int> path, result;
  vector<bool> visited(n+1, false);
  cin>>n>>m;
  init_g(n);
  for(i=0;i<m;i++) {
    cin>>r>>c;
    if(r!=c) {
      g[r][c] = 1;
      g[c][r] = 1;
    }
  }
  path.push_back(1);
  visited[1] = true;cout<<endl;
  solve(path, visited, n, result);
  for(i=0;i<result.size();i++) {
    cout<<result[i]<<' ';
  }
  cout<<endl;
  return 0;
}
