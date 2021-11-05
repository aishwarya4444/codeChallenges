/*

range sum query
indexing is 1 based

input
4
5 2 3 4
3
2 4
2 3
4 4

output
9
5
4
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int bit[20] = {0};
int a[20];
int n, q;
int l, r;

// range sum query
void update(int i, int inc) {
  while(i<=n) {
    bit[i] += inc;
    i += (i&(-i));
  }
}

// sum till index i
int query(int i) {
  int sum = 0;
  while(i>0) {
    sum += bit[i];
    i -= (i&(-i));
  }
  return sum;
}

int main(){
  cin>>n;

  for(int i=1; i<=n; i++) {
    cin>>a[i];
    update(i, a[i]);
  }

  cin>>q;
  while(q--) {
    cin>>l>>r;
    cout<<query(r)-query(l-1)<<endl;
  }

  return 0;
}
