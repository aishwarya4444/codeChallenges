/*
https://cses.fi/problemset/task/1092

simple solution referred
https://github.com/iamprayush/cses-problemset-solutions/blob/master/solutions/Introductory%20Problems/two-sets.cpp

mod 3 and 4 solutions
https://www.youtube.com/watch?v=_JXb1AjcPlU
https://www.reddit.com/r/learnprogramming/comments/n9ql5a/cses_problem_two_sets/
william lin https://youtu.be/dZ_6MS14Mg4?t=1204
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

  ll n, sum=0, total=0;
  vector<ll> ar1, ar2;

  cin>>n;
  total = n*(n+1)/2;

  if(total%2) {
    cout<<"NO\n";
    return 0;
  }

  total /= 2;
  while(n) {
    if(sum+n<=total) {
      sum += n;
      ar1.push_back(n);
    } else {
      ar2.push_back(n);
    }
    n--;
  }

  cout<<"YES\n";

  cout<<ar1.size()<<endl;
  for(ll num: ar1) {
    cout<<num<<' ';
  }
  cout<<endl;

  cout<<ar2.size()<<endl;
  for(ll num: ar2) {
    cout<<num<<' ';
  }

  return 0;
}
