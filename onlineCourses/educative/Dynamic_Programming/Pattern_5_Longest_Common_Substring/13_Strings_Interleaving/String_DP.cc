// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5689922476310528

#include<iostream>
#include<cstring>
using namespace std;

// https://leetcode.com/problems/interleaving-string/

bool help(string &a, string &b, string &ab, int i, int j) {
  if(i == a.size() && j == b.size()) {
    return true;
  }
  if(i > a.size() || j > b.size()) {
    return false;
  }
  if(a[i] == ab[i+j]) {
    return help(a, b, ab, i+1, j);
  }
  if(b[j] == ab[i+j]) {
    return help(a, b, ab, i, j+1);
  }
  return false;
}

bool isInterleaving(string a, string b, string ab) {
  if(a.size()+b.size() != ab.size()) {
    return false;
  }

  int i, j, A=a.size(), B=b.size();
  bool dp[A+1][B+1];

  dp[0][0] = true;
  for(i=1; i<=A; i++) {
    dp[i][0] = a[i-1]==ab[i-1] && dp[i-1][0];
  }
  for(j=1; j<=B; j++) {
    dp[0][j] = b[j-1]==ab[j-1] && dp[0][j-1];
  }
  for(i=1; i<=A; i++) {
    for(j=1; j<=B; j++) {
      dp[i][j] = (a[i-1]==ab[i+j-1] && dp[i-1][j]) || (b[j-1]==ab[i+j-1] && dp[i][j-1]);
    }
  }
  return dp[A][B];
}

int main() {
  cout<<isInterleaving("abd", "cef", "abcdef")<<'\n';
  cout<<isInterleaving("abd", "cef", "adcbef")<<'\n';
  cout<<isInterleaving("abc", "def", "abdccf")<<'\n';
  cout<<isInterleaving("abcdef", "mnop", "mnaobcdepf")<<'\n';
  return 0;
}
