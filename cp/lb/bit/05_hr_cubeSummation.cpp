/*
https://www.hackerrank.com/challenges/cube-summation/problem
https://allhackerranksolutions.blogspot.com/2016/08/cube-summation-hacker-rank-solution.html
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 101;

ll bit[N][N][N];
int t, n, m;

int lsb(int i) {
  return (i&(-i));
}

void update(int i, int j, int k, ll val) {
  for(int x=i; x<=n; x+=lsb(x)) {
    for(int y=j; y<=n; y+=lsb(y)) {
      for(int z=k; z<=n; z+=lsb(z)) {
        bit[x][y][z] += val;
      }
    }
  }
}

ll query(int i, int j, int k) {
  ll sum = 0;
  for(int x=i; x>0; x-=lsb(x)) {
    for(int y=j; y>0; y-=lsb(y)) {
      for(int z=k; z>0; z-=lsb(z)) {
        sum += bit[x][y][z];
      }
    }
  }
  return sum;
}

ll range_query(int x1, int y1, int z1, int x2, int y2, int z2) {
  ll v1 = query(x2,y2,z2) - query(x1-1,y2,z2) - query(x2,y1-1,z2) + query(x1-1,y1-1,z2); // upper layer of cube
  ll v2 = query(x2,y2,z1-1) - query(x1-1,y2,z1-1) - query(x2,y1-1,z1-1) + query(x1-1,y1-1,z1-1); // lower layer of cube
  ll ans = v1 - v2;
  return ans;
}

int main(){
  cin>>t;

  while(t--) {

    cin>>n>>m;

    memset(bit, 0, sizeof bit);

    while(m--) {
      int x1, y1, z1, x2, y2, z2;
      ll W;
      string query;
      cin>>query;

      if(query=="UPDATE") {
        cin>>x1>>y1>>z1>>W;
        ll curval = range_query(x1,y1,z1,x1,y1,z1);
        update(x1, y1, z1, W - curval);
      } else {
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        cout<<range_query(x1, y1, z1, x2, y2, z2)<<endl;
      }

    }

  }

  return 0;
}

