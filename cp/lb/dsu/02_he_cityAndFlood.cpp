/*
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-flood-1/
*/

#include <bits/stdc++.h>
using namespace std;

struct dsu {
  vector<int> par;
  vector<int> rank;

  void make_sets(int n) {
    rank.assign(n+1, 0);
    par.resize(n+1);
    iota(par.begin(), par.end(), 0);
  }

  int find_set(int a) {
    if(a == par[a]) {
      return a;
    }
    // path compression
    return par[a] = find_set(par[a]);
  }

  // union by rank
  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
      if(rank[a] < rank[b]) {
        swap(a, b);
      }
      par[b] = a;
      if(rank[a] == rank[b]) {
        rank[a]++;
      }
    }
  }

};


int main(){
  dsu gr;
  int n, k, i, j;

  cin>>n>>k;

  gr.make_sets(n);
  while(k--) {
    cin>>i>>j;
    gr.union_sets(i, j);
  }

  int ans = 0;
  for(int a=1; a<=n; a++) {
    if(a == gr.par[a]) ans++;
  }
  cout<<ans;

  return 0;
}
