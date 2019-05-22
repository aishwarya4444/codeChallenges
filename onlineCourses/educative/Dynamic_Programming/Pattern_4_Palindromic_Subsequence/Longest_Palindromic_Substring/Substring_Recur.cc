// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5661601461960704

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
  int c1=0, c2=0, c3=0;
  if(s[l]==s[r]) {
    c1 = r-l+1;
    if(c1-2 == solve(s, l+1, r-1)) {
      return c1;
    }
    else {
      c1 = 0;
    }
  }
  c2 = solve(s, l+1, r);
  c3 = solve(s, l, r-1);
  return max(c1, max(c2, c3));
}

int substring(string &s) {
  return solve(s, 0, s.size()-1);
}

int main(void) {
  string s("abdbca");
  cout<<substring(s)<<'\n';

  s="cddpd";
  cout<<substring(s)<<'\n';

  s="pqr";
  cout<<substring(s)<<'\n';

  return 0;
}