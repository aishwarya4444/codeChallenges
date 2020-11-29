/*
https://codeforces.com/problemset/problem/894/A
*/

// https://leetcode.com/problems/distinct-subsequences/

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

// recursive
int help(string &s1, int i, string &s2, int j) {
  if(i==s1.size()) {
    return 1;
  }
  if(j==s2.size()) {
    return 0;
  }
  int c1=0, c2=0, c3=0;
  if(s1[i]==s2[j]) {
    c1 = help(s1, i+1, s2, j+1);
    c2 = help(s1, i, s2, j+1);
  } else {
    c3 = help(s1, i, s2, j+1);
  }
  return c1+c2+c3;
}

int main() {
  int r, c, R, C, len = 0;
  string s1, s2;
  vector<vector<int> > dp;

  s1 = "QAQ";
  cin>>s2;

  R = s1.size();
  C = s2.size();

  dp = vector<vector<int> >(R+1, vector<int>(C+1, 0));

  for(c=0; c<=C; c++) {
    dp[0][c] = 1;
  }

  for(r=1; r<=R; r++) {
    for(c=1; c<=C; c++) {
      if(s1[r-1]==s2[c-1]) {
        dp[r][c] = dp[r-1][c-1];
      }
      dp[r][c] += dp[r][c-1];
    }
  }

  // cout<<help(s1, 0, s2, 0)<<endl;
  cout<<dp[R][C]<<endl;
  return 0;
}
