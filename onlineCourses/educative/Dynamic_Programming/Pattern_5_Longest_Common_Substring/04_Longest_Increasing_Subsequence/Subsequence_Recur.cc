// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5733679603122176

#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &v, int curr, int prev) {
  if(curr == v.size()) {
    return 0;
  }
  int c1=0, c2=0;
  if(prev<0 || v[curr]>v[prev]) {
    c1 = 1+solve(v, curr+1, curr);
  }
  c2 = solve(v, curr+1, prev);
  return max(c1, c2);
}

void lis(vector<int> &v) {
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
  lis(v);

  // [ -4, 10, 3, 7, 15 ]
  v.clear();
  v.push_back(-4);
  v.push_back(10);
  v.push_back(3);
  v.push_back(7);
  v.push_back(15);
  lis(v);

  return 0;
}
