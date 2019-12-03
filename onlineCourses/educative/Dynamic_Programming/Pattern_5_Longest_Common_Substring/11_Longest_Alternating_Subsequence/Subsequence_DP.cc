// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5643365030821888

#include<iostream>
#include<vector>

using namespace std;

int subsequence(vector<int> &n) {
  int length=1, r, c, dp[n.size()][2];

  if(n.size()==0) {
    return 0;
  }

  for(r=0; r<n.size(); r++) {
    dp[r][0] = dp[r][1] = 1;
  }

  // 0th column has last 2 elements in descending order
  // 1st column has last 2 elements in ascending order
  for(r=0; r<n.size(); r++) {
    for(c=0; c<r; c++) {
      if(n[r]>n[c]) {
        dp[r][0] = max(length, 1+dp[c][1]);
        length = max(length, dp[r][0]);
      } else {
        dp[r][1] = max(length, 1+dp[c][0]);
        length = max(length, dp[r][1]);
      }
    }
  }
  return length;
}

int main() {
  vector<int> n;

  // case 1
  n = { 1, 2, 3, 4 };
  cout<<subsequence(n)<<'\n';

  // case 2
  n.clear();
  n = { 3, 2, 1, 4 };
  cout<<subsequence(n)<<'\n';

  // case 3
  n.clear();
  n = { 1, 3, 2, 4 };
  cout<<subsequence(n)<<'\n';

  n.clear();
  n = { 10, 22, 9, 33, 49, 50, 31, 60 };
  cout<<subsequence(n)<<'\n';

  return 0;
}

// compile using g++ -std=c++11 Subsequence_Recur.cc
