/*
https://cses.fi/problemset/task/1094
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

  int n;
  ll prev, curr, moves = 0;

  cin>>n;
  cin>>prev;

  for(int i=2; i<=n; i++) {
    cin>>curr;
    if(prev > curr) {
      moves += prev-curr;
    } else {
      prev = curr;
    }
  }

  cout<<moves;

  return 0;
}
