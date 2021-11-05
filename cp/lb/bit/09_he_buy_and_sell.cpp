/*
https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/buy-and-sell/
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const int N = 2e5;

int bit[N+5];
int n, q;
unordered_map<string, int> mp;
unordered_map<string, int> freq;
string fruit;
int price;

int lsb(int i) {
  return (i&(-i));
}

void update(int i, int val) {
  for(i; i<=N; i+=lsb(i)) {
    bit[i] += val;
  }
}

int query(int i) {
  int val = 0;

  for(i; i>0; i-=lsb(i)) {
    val += bit[i];
  }

  return val;
}

int main(){
  char qry;

  cin>>n;

  for(int i=1; i<=n; i++) {
    cin>>fruit>>price;
    mp[fruit] = price;
  }

  memset(bit, 0, sizeof bit);

  cin>>q;

  while(q--) {
    cin>>qry;
    if(qry=='+') {
      cin>>fruit;
      freq[fruit]++;
      update(mp[fruit], 1);
    } else if(qry=='-') {
      cin>>fruit;
      if(freq[fruit] > 0) { // if fruit is not there .. quantity cannot be reduced
        freq[fruit]--;
        update(mp[fruit], -1);
      }
    } else {
      cin>>price;
      cout<<query(N) - query(price)<<endl;
    }
  }

  return 0;
}
