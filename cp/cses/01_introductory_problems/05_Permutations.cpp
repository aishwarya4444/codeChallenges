/*
https://cses.fi/problemset/task/1070
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

  int n;

  cin>>n;

  if(n==2 || n==3) {
    cout<<"NO SOLUTION";
    return 0;
  }

  for(int i=2; i<=n; i+=2) {
    cout<<i<<' ';
  }

  for(int i=1; i<=n; i+=2) {
    cout<<i<<' ';
  }

  return 0;
}
