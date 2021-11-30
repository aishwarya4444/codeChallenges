/*
https://cses.fi/problemset/task/1083
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a[200002];

int main(){

  int n;
  cin>>n;

  // n-1 elements are given
  for(int i=0; i<n-1; i++) {
    cin>>a[i];
  }

  for(int i=0; i<n; ) {
    int j = a[i]-1;
    if(j>=0 && j<n && a[i] != a[j]) {
      swap(a[i], a[j]);
    } else {
      i++;
    }
  }

  for(int i=0; i<n; i++) {
    if(a[i] != i+1) {
      cout<<i+1;
    }
  }

  return 0;
}

// other approach is to take sum of numbers
// and subtract it from n*(n+1)/2
