/*
https://vjudge.net/problem/UVA-11284
https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2259

https://vjudge.net/solution/33464776
https://www.udebug.com/UVa/11284
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int n, m, p;
ll dist[51][51];
int opera[13];
ll diff[13];
ll dp[(1<<14)+1][14];

ll solve(int mask, int pos) {
  if(mask == ((1<<(1+p))-1) ) {
    return -dist[opera[pos]][0];
  }

  if(dp[mask][pos] != -1) {
    return dp[mask][pos];
  }

  ll ans = -dist[opera[pos]][0];

  for(int i=1; i<=p; i++) {
    if( mask&(1<<i) ) continue;
    ans = max(ans, solve(mask|(1<<i), i) + diff[i] - dist[opera[i]][opera[pos]]);
  }

  return dp[mask][pos] = ans;
}

int main(){
  int t;
  int u, v;
  double cost;
  int dollars, cents;

  cin>>t;
  while(t--) {
    cin>>n>>m;

    // init distances
    for(int i=0; i<=n; i++) {
      dist[i][i] = 0;
      for(int j=i+1; j<=n; j++) {
        dist[i][j] = INT_MAX;
        dist[j][i] = INT_MAX;
      }
    }

    // input distances
    for(int i=1; i<=m; i++) {
      cin>>u>>v>>cost;
      ll d = (ll)round(100.0*cost);
      dist[u][v] = min(d, dist[u][v]);
      dist[v][u] = min(d, dist[v][u]);
    }

    // Floyd Warshall
    for (int k=0; k <= n; k++){
      for (int i=0; i <= n; i++){
        for (int j=0; j <= n; j++){
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    cin>>p;
    for(int i=1; i<=p; i++) {
      cin>>opera[i];
      // another way to input cost
      scanf("%d.%d", &dollars, &cents);
      ll d = 100*dollars + cents;
      diff[i] = d;
    }

    memset(dp, -1, sizeof dp);
    // init value of mask is 1 because we start from house number 0
    // init value of pos is 0 because it is position of house
    // operas are numbered from 1 to p
    ll ans = solve(1, 0);
    if(ans <= 0) {
      cout<<"Don't leave the house\n";
    } else {
      cout<<"Daniel can save $"<<(ans/100)<<'.'<<setw(2)<<setfill('0')<<(ans%100)<<endl;
    }
  }

}
