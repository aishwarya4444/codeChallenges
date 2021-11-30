/*
https://cses.fi/problemset/task/1623
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int p[20];
int n;

int main(){
  ll sum = 0, total = 0, maxSum = 0;

  cin>>n;
  for(int i=0; i<n; i++) {
    cin>>p[i];
    sum += p[i];
  }

  for(int mask=1; mask<(1<<n); mask++) {
    total = 0;
    for(int i=0; i<n; i++) {
      if(mask&(1<<i)) total += p[i];
    }
    if(total<=sum/2) {
      maxSum = max(maxSum, total);
    }

  }

  cout<<sum-2*maxSum;

  return 0;
}
