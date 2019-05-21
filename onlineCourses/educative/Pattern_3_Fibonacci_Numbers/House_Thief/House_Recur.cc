// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5676982813589504

#include<iostream>
#include<vector>
using namespace std;

int _solve(vector<int> &house, int i) {
  if(i>=house.size()) {
    return 0;
  }
  int profit1 = house[i] + _solve(house, i+2),
    profit2 = _solve(house, i+1);
  return max(profit1, profit2);
}

int solve(vector<int> &house) {
  return _solve(house, 0);
}

int main(void) {
  vector<int> house;

  // wealth in houses
  house.push_back(2);
  house.push_back(5);
  house.push_back(1);
  house.push_back(3);
  house.push_back(6);
  house.push_back(2);
  house.push_back(4);
  cout<<solve(house)<<'\n';

  // wealth in houses
  house.clear();
  house.push_back(2);
  house.push_back(10);
  house.push_back(14);
  house.push_back(8);
  house.push_back(1);
  cout<<solve(house)<<'\n';
}