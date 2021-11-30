/*
https://cses.fi/problemset/task/1618
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

  ll num, den = 5;
  int cnt = 0;

  cin>>num;
  while(num/den) {
    cnt += num/den;
    den *= 5;
  }

  cout<<cnt;

  return 0;
}
