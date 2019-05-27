// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5685057352105984

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minJumps(vector<int> &J, int i) {
  if(i>=J.size()-1) {
    return 0;
  }

  if(J[i]==0) {
    return INT_MAX;
  }

  int j, jumps, totalJumps=INT_MAX;
  for(j=i+1; j<=i+J[i]; j++) {
    jumps = minJumps(J, j);
    if(jumps!=INT_MAX) {
      totalJumps = min(totalJumps, jumps+1);
    }
  }
  return totalJumps;
}

int minJumps(vector<int> &jumps) {
  return minJumps(jumps, 0);
}

int main(void ) {
  vector<int> jumps;

  // jumps
  jumps.push_back(2);
  jumps.push_back(1);
  jumps.push_back(1);
  jumps.push_back(1);
  jumps.push_back(4);

  cout<<minJumps(jumps)<<'\n';

  // jumps
  jumps.clear();
  jumps.push_back(1);
  jumps.push_back(1);
  jumps.push_back(3);
  jumps.push_back(6);
  jumps.push_back(9);
  jumps.push_back(3);
  jumps.push_back(0);
  jumps.push_back(1);
  jumps.push_back(3);

  cout<<minJumps(jumps)<<'\n';

  return 0;
}