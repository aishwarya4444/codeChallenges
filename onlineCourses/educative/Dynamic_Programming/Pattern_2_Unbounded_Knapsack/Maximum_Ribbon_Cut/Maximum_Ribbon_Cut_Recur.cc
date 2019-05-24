// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5709198289534976

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int ribbonCut(int i, vector<int> &R, int length) {
  if(i==R.size()) {
    return INT_MIN;
  }
  if(length==0) {
    return 0;
  }
  int numCut1=INT_MIN, numCut2=0;
  if(length>=R[i]) {
    numCut1 = ribbonCut(i, R, length-R[i]);
    if(numCut1!=INT_MIN) {
      numCut1++;
    }
  }
  numCut2 = ribbonCut(i+1, R, length);
  return max(numCut1, numCut2);
}

int ribbonCut(vector<int> &R, int length) {
  int maxCut = ribbonCut(0, R, length);
  return maxCut==INT_MIN ? -1 : maxCut;
}

int main(void) {
  int length;
  vector<int> ribbons;

  // ribbons
  ribbons.push_back(2);
  ribbons.push_back(3);
  ribbons.push_back(5);

  // length
  length = 5;
  cout<<ribbonCut(ribbons, length)<<'\n';


  // ribbons
  ribbons.clear();
  ribbons.push_back(2);
  ribbons.push_back(3);

  // length
  length = 7;
  cout<<ribbonCut(ribbons, length)<<'\n';

  // ribbons
  ribbons.clear();
  ribbons.push_back(3);
  ribbons.push_back(5);
  ribbons.push_back(7);

  // length
  length = 13;
  cout<<ribbonCut(ribbons, length)<<'\n';

  // ribbons
  ribbons.clear();
  ribbons.push_back(3);
  ribbons.push_back(5);

  // length
  length = 7;
  cout<<ribbonCut(ribbons, length)<<'\n';

  return 0;
}