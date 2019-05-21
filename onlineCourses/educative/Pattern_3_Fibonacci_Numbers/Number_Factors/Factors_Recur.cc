// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5724313353191424

#include<iostream>
using namespace std;

int factors(int n) {
  if(n<3) {
    return 1;
  }
  if(n==3) {
    return 2;
  }
  return factors(n-1) + factors(n-3) + factors(n-4);
}

int main(void) {
  cout<<factors(4)<<'\n';
  cout<<factors(5)<<'\n';
  cout<<factors(6)<<'\n';

  return 0;
}