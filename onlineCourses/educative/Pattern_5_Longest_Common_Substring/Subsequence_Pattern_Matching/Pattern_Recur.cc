// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5718922095493120

#include<iostream>
#include<cstring>
using namespace std;

int solve(string &s1, string &s2, int i, int j) {
  if(j==s2.size()) {
    return 1;
  }
  if(i==s1.size()) {
    return 0;
  }
  int c1=0, c2=0;
  if(s1[i]==s2[j]) {
    c1 = solve(s1, s2, i+1, j+1);
  }
  c2 = solve(s1, s2, i+1, j);
  return c1+c2;
}

void match(string str, string pat) {
  cout<<str<<' '<<pat<<' '<<solve(str, pat, 0, 0)<<'\n';
}

int main(void) {
  match("baxmx", "ax");
  match("tomorrow", "tor");
  return 0;
}