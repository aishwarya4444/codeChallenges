/*
https://cses.fi/problemset/task/1617
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int mod = 1e9+7;

int main(){

  int n;
  ll ans = 1;

  cin>>n;

  for(int i=1; i<=n; i++) {
    ans = (ans*2)%mod;
  }

  cout<<ans;

  return 0;
}
