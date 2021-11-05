/*
https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/counting-in-byteland/
*/

#include <bits/stdc++.h>
using namespace std;

#define ll unsigned long long int

// N=101 gave error
const int N = 210;

ll bit[N][N][N];
int n, q;

int lsb(int i) {
  return (i&(-i));
}

void update(int x, int y, int z, ll val) {
  for(int i=x; i<=N; i+=lsb(i)) { // keeping "N" instead of "n" to avoid error
    for(int j=y; j<=N; j+=lsb(j)) {
      for(int k=z; k<=N; k+=lsb(k)) {
        bit[i][j][k] += val;
      }
    }
  }
}

ll query(int x, int y, int z) {
  ll val = 0;

  for(int i=x; i>0; i-=lsb(i)) {
    for(int j=y; j>0; j-=lsb(j)) {
      for(int k=z; k>0; k-=lsb(k)) {
        val += bit[i][j][k];
      }
    }
  }

  return val;
}

ll range_query(int x, int y, int z, int X, int Y, int Z) {
  ll valUpper = query(X, Y, Z) - query(x-1, Y, Z) - query(X, y-1, Z) + query(x-1, y-1, Z);
  ll valLower = query(X, Y, z-1) - query(x-1, Y, z-1) - query(X, y-1, z-1) + query(x-1, y-1, z-1);
  return valUpper - valLower;
}

int main(){
  int type;
  ll total = 0;

  cin>>n>>q;

  while(q--) {
    cin>>type;
    if(type==1) {
      // update
      int x, y, z;
      ll val;
      cin>>x>>y>>z>>val;
      x++, y++, z++;
      update(x, y, z, val);
      total += val;
    } else {
      // query
      int x, y, z, X, Y, Z;
      cin>>x>>y>>z>>X>>Y>>Z;
      x++, y++, z++;
      X++, Y++, Z++;
      cout<<total - range_query(x, y, z, X, Y, Z)<<endl;
    }
  }

  return 0;
}
