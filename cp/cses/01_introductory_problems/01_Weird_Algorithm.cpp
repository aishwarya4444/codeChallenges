/*
https://cses.fi/problemset/task/1068
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

  ll n;
  // if this is taken as "int" then error happens
  // because 3*n can overflow int
  cin>>n;

  while(true) {
    cout<<n<<' ';
    if(n==1) break;
    if(n%2 == 0) {
      n /= 2;
    } else {
      n = 3*n+1;
    }
  }

  return 0;
}
