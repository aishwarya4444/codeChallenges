/*

range max query
we cannot find max in range [l, r]
but we can always find max in range [1, r]

input
4
5 2 13 4
3
4
2
3

output
13
5
13

*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int bit[20] = {0};
int a[20];
int n, q;
int idx;

void update(int i, int val) {

  while(i<=n) {
    bit[i] = max(bit[i], val);
    i += (i&(-i));
  }
}

int query(int i) {
  int sum = 0;
  while(i>0) {
    sum = max(bit[i], sum);
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
    cin>>idx;
    cout<<query(idx)<<endl;
  }

  return 0;
}
