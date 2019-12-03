// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5657535201673216

#include<iostream>
#include<cstring>
using namespace std;

int solve(string &s1, string &s2, int i, int j, int count) {
  if(i==s1.size() || j==s2.size()) {
    return count;
  }
  if(s1[i]==s2[j]) {
    return 1 + solve(s1, s2, i+1, j+1, count);
  }
  int c1, c2;
  c1 = solve(s1, s2, i+1, j, count);
  c2 = solve(s1, s2, i, j+1, count);
  return max(c1, c2);
}

int subsequence(string s1, string s2) {
  return solve(s1, s2, 0, 0, 0);
}

int main(void) {
  cout<<subsequence("abdca", "cbda")<<'\n';
  cout<<subsequence("passport", "ppsspt")<<'\n';
  return 0;
}
