/*
https://cses.fi/problemset/task/1071
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

  int t;
  ll r, c, skip;

  cin>>t;
  while(t--) {
    cin>>r>>c;

    ll mx = max(r, c);

    ll lb = (mx-1)*(mx-1);

    // [1] for even value of mx .. start from top  .. move down  .. and then left
    // [2] for odd value of mx  .. start from left .. move right .. and then up
    // for even mx .. if we swap (r,c) .. we can follow approach [2]
    if(mx%2 == 0) {
      r += c;
      c = r-c;
      r = r-c;
    }

    // start from left .. move to right .. and then up
    if(r==mx) {
      skip = c;
    } else {
      skip = c+(mx-r);
    }

    cout<<lb+skip<<endl;
  }

  return 0;
}
