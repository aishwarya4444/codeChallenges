/*
https://www.spoj.com/problems/CLFLARR/
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

struct dsu {
  vector<int> par;

  void init(int n) {
    par.resize(n);
    iota(par.begin(), par.end(), 0);
  }

  // find parent of x
  int get(int x) {
    if(x==par[x]) {
      return x;
    }
    return par[x] = get(par[x]);
  }

  // union of x and y
  void unite(int x, int y) {
    x = get(x);
    y = get(y);
    if(x != y) {
      par[x] = max(par[x], par[y]);
      par[y] = max(par[x], par[y]);
    }
  }

};

int main(){

  int n, q;
  cin>>n>>q;

  int l[q], r[q], c[q];
  for(int i=0; i<q; i++) {
    cin>>l[i]>>r[i]>>c[i];
  }

  dsu g;
  int res[n+2] = {};
  g.init(n+2);

  for(int i=q-1; i>=0; i--) {
    int index = g.get(l[i]);

    while(index <= r[i]) {
      res[index] = c[i];
      g.unite(index, index+1);
      // get the next position to right of index which is not coloured
      index = g.get(index);
    }

  }

  for(int i=1; i<=n; i++) {
    cout<<res[i]<<endl;
  }

  return 0;
}
