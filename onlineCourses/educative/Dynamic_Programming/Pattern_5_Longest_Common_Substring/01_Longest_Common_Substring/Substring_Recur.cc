// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5750031617359872

#include<iostream>
#include<cstring>
using namespace std;

int solve(string &s1, string &s2, int i, int j, int count) {
  if(i==s1.size() || j==s2.size()) {
    return count;
  }
  int c1, c2;
  if(s1[i] == s2[j]) {
    count = solve(s1, s2, i+1, j+1, count+1);
  }
  c1 = solve(s1, s2, i+1, j, 0);
  c2 = solve(s1, s2, i, j+1, 0);
  return max(count, max(c1, c2));
}

int substring(string s1, string s2) {
  cout<<s1<<' '<<s2<<'\n';
  return solve(s1, s2, 0, 0, 0);
}

int main(void) {
  cout<<substring("abdca", "cbda")<<'\n';
  cout<<substring("passport", "ppsspt")<<'\n';
  return 0;
}