// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5733679603122176

#include<iostream>
#include<vector>
using namespace std;

void lis(vector<int> &v) {
  cout<<solve(v, 1, 0)<<'\n';
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
