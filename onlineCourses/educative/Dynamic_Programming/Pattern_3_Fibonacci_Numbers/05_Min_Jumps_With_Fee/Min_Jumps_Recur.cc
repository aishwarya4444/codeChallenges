// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5717424225648640

#include<iostream>
#include<vector>
using namespace std;

int minFee(vector<int> &fee, int index) {
  if(index > fee.size()-1) {
    return 0;
  }

  int step1, step2, step3, minimumFee;

  step1 = minFee(fee, index+1);
  step2 = minFee(fee, index+2);
  step3 = minFee(fee, index+3);

  minimumFee = min(step1, min(step2, step3));

  return minimumFee + fee[index];
}

int main(void ) {
  vector<int> fee;

  // fee
  fee.push_back(1);
  fee.push_back(2);
  fee.push_back(5);
  fee.push_back(2);
  fee.push_back(1);
  fee.push_back(2);

  cout<<minFee(fee, 0)<<'\n';

  // fee
  fee.clear();
  fee.push_back(2);
  fee.push_back(3);
  fee.push_back(4);
  fee.push_back(5);

  cout<<minFee(fee, 0)<<'\n';

  return 0;
}