// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5748119283171328

#include<iostream>
#include<cstring>
using namespace std;

int solve(string &s, int l, int r) {
  if(l>r) {
    return 0;
  }
  if(l==r) {
    return 1;
  }
  if(s[l]==s[r]) {
    return 2+solve(s, l+1, r-1);
  }

  return max(solve(s, l+1, r), solve(s, l, r-1));
}

int subsequence(string &s) {
  return solve(s, 0, s.size()-1);
}

int main(void) {
  string s("abdbca");
  cout<<subsequence(s)<<'\n';

  s="cddpd";
  cout<<subsequence(s)<<'\n';

  s="pqr";
  cout<<subsequence(s)<<'\n';

  return 0;
}