/*
https://cses.fi/problemset/task/1069
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

  string s;
  int cnt, maxCnt = 0;

  cin>>s;

  s = '_'+s;

  for(int i=1; i<s.size(); i++) {
    if(s[i-1]==s[i]) {
      cnt++;
    } else {
      cnt = 1;
    }

    maxCnt = max(maxCnt, cnt);
  }

  cout<<maxCnt;

  return 0;
}
