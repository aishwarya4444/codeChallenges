/*
https://www.spoj.com/problems/UPDATEIT/

bit - https://github.com/Shah-Shishir/SPOJ-Solutions/blob/master/UPDATEIT%20-%20Update%20the%20array%20!.cpp
dp - https://github.com/akkisocc/Spoj-Solutions/blob/master/UPDATEIT%20-%20Update%20the%20array%20!.cpp

range update
point query
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 10001;

ll bit[N];
int t, n, u, q;
int l, r, val;

void update(int i, int val) {
  while(i<=n) {
    bit[i] += val;
    i += (i&(-i));
  }
}

ll query(int i) {
  ll sum = 0;
  while(i>0) {
    sum += bit[i];
    i -= (i&(-i));
  }
  return sum;
}

int main(){
  cin>>t;

  while(t--) {

    cin>>n>>u;

    memset(bit, 0, sizeof bit);


    while(u--) {
      cin>>l>>r>>val;
      l++;
      r++;
      update(l, val);
      update(r+1, -val);
    }

    cin>>q;
    while(q--) {
      cin>>l;
      l++;
      cout<<query(l)<<endl;
    }
  }

  return 0;
}
