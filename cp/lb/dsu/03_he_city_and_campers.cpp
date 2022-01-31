/*
https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/practice-problems/algorithm/city-and-campers/
*/

#include <bits/stdc++.h>
using namespace std;

struct dsu {
  vector<int> par;
  vector<int> size;
  multiset<int> sizes;

  void make_sets(int n) {
    size.assign(n+1, 1);
    par.resize(n+1);
    iota(par.begin(), par.end(), 0);
    sizes.insert(size.begin()+1, size.end());
  }

  int find_set(int a) {
    if(a == par[a]) {
      return a;
    }
    // path compression
    return par[a] = find_set(par[a]);
  }

  void merge(int a, int b) {
    // if I give value of element that has to be erased
    // then all values will be deleted in multiset
    // hence I give iterator
    // sizes.erase(sizes.find(size[a]));
    sizes.erase(sizes.lower_bound(size[a]));
    sizes.erase(sizes.lower_bound(size[b]));

    sizes.insert(size[a]+size[b]);
  }

  // union by size
  void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
      if(size[a] < size[b]) {
        swap(a, b);
      }
      par[b] = a;
      merge(a, b);
      size[a] += size[b];
    }
  }

};


int main(){
  dsu gr;
  int n, q, a, b;

  cin>>n>>q;

  gr.make_sets(n);
  while(q--) {
    cin>>a>>b;
    gr.union_sets(a, b);
    if(gr.sizes.size() == 1) {
      cout<<0<<endl;
    } else {
      int mn = *(gr.sizes.begin());
      int mx = *(--gr.sizes.end());
      cout<<mx-mn<<endl;
    }
  }

  return 0;
}
