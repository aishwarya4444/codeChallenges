/*
https://codeforces.com/problemset/problem/11/D

Sanyam TLE
https://codeforces.com/contest/11/submission/61102514
My TLE
https://codeforces.com/contest/11/submission/133396819

Sanyam Accepted
https://codeforces.com/contest/11/submission/61102706
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int n, m;
int g[19][19];
ll dp[(1<<19)][19];

ll solve(int mask, int curr, int startNode) {
  if(__builtin_popcount(mask) == n) {
    return g[curr][startNode];
  }

  if(dp[mask][curr] != -1) {
    return dp[mask][curr];
  }

  ll ans = 0;

  // cycle size should be more than 2
  // cycleSize=2 is not taken because -
  //   [1] A simple cycle is a cycle with no repeated vertices or edges.
  //   [2] There is no more than one edge connecting any pair of vertices.
  if(__builtin_popcount(mask) > 2) {
    ans = g[curr][startNode];
  }

  // we pick up the smallest node in a cycle
  // left/right side of that node will give 2 counts of same cycle
  for(int i=startNode+1; i<n; i++) {
    if((mask&(1<<i))==0 && g[curr][i]) {
      ans += solve(mask|(1<<i), i, startNode);
    }
  }

  return dp[mask][curr] = ans;
}

int main(){
  int u, v;
  cin>>n>>m;

  for(int i=1; i<=m; i++) {
    cin>>u>>v;
    u--;
    v--;
    g[u][v] = 1;
    g[v][u] = 1;
  }

  ll ans = 0;

  for(int startNode=0; startNode<n; startNode++) {
    memset(dp, -1, sizeof dp);
    ans += solve((1<<startNode), startNode, startNode)/2;
    // divide by 2 because
    // left/right side of that node will give 2 counts of same cycle
  }

  cout<<ans;

  return 0;

}

