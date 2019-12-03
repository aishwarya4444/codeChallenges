// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5634208160546816

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &v, int curr, int prev) {
  if(curr==v.size()) {
    return 0;
  }
  int s1=0, s2=0;
  if(prev<0 || v[curr]>v[prev]) {
    s1 = v[curr] + solve(v, curr+1, curr);
  }
  s2 = solve(v, curr+1, prev);
  return max(s1, s2);
}

void msis(vector<int> &v) {
  cout<<solve(v, 0, -1)<<'\n';
}

int main(void) {
  vector<int> v;

  // [ 4, 2, 3, 6, 10, 1, 12 ]
  v.push_back(4);
  v.push_back(2);
  v.push_back(3);
  v.push_back(6);
  v.push_back(10);
  v.push_back(1);
  v.push_back(12);
  msis(v);

  // [ -4, 10, 3, 7, 15 ]
  v.clear();
  v.push_back(-4);
  v.push_back(10);
  v.push_back(3);
  v.push_back(7);
  v.push_back(15);
  msis(v);

  // [ 1, 3, 8, 4, 14, 6, 14, 1, 9, 4, 13, 3, 11, 17, 29 ]
  v.clear();
  v.push_back(1);
  v.push_back(3);
  v.push_back(8);
  v.push_back(4);
  v.push_back(14);
  v.push_back(6);
  v.push_back(14);
  v.push_back(1);
  v.push_back(9);
  v.push_back(4);
  v.push_back(13);
  v.push_back(3);
  v.push_back(11);
  v.push_back(17);
  v.push_back(29);
  msis(v);

  return 0;
}
