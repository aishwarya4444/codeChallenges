/*
https://cses.fi/problemset/task/1072
https://japlofficial.github.io/posts/cses/two_knights/1.htm
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

  ll n;
  cin>>n;

  for(ll k=1; k<=n; k++) {
    // size of board = k x k
    // total number of positions = k^2
    // if 1 place is fixed .. then (k^2 - 1) places are left
    // 1 place can be fixed in k^2 ways
    // total ways = k^2 * (k^2-1) / 2
    // divide by 2 because both knights are identical
    ll total = (k*k)*(k*k-1)/2;

    // 8 positions can be attacked from 1 place
    // increase / decrease row by 1 or 2
    // increase / decrease col by 2 or 1
    // divide by 2 because both knights are identical
    ll attack = 8*(k-1)*(k-2)/2;
    cout<<total-attack<<endl;
  }

  return 0;
}
