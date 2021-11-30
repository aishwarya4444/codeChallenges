/*
https://cses.fi/problemset/task/1754

https://discuss.codechef.com/t/coin-piles-problem-from-cses/28647/10
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

  int t;
  ll a, b;

  cin>>t;

  while(t--) {
    cin>>a>>b;

    // to understand why we are using this condition
    // refer the codechef comment above
    if((2*a-b) >=0 &&
      (2*a-b)%3 ==0 &&
      (2*b-a) >=0 &&
      (2*b-a)%3 == 0) {
      cout<<"YES\n";
    } else {
      cout<<"NO\n";
    }
  }

  return 0;
}
