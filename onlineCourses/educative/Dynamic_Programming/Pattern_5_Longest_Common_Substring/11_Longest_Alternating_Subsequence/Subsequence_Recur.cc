// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5643365030821888

#include<iostream>
#include<vector>

using namespace std;

int help(vector<int> &n, int prev, int next, bool small) {
  if(prev == n.size()) {
    return 0;
  }
  if(next == n.size()) {
    return 1;
  }
  int c1=0, c2=0;
  if(!small && n[prev]>n[next]) {
    c1 = 1+help(n, next, next+1, !small);
  } else if(small && n[prev]<n[next]) {
    c1 = 1+help(n, next, next+1, !small);
  } else {
    c2 = help(n, prev, next+1, small);
  }
  return max(c1, c2);
}

int subsequence(vector<int> &n) {
  return max( help(n, 0, 1, false), help(n, 0, 1, true) );
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
