// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5649202965118976

#include<iostream>
using namespace std;

int stairs(int n) {
  if(n==0 || n==1) {
    return 1;
  }
  if(n==2) {
    return 2;
  }
  return stairs(n-1)+stairs(n-2)+stairs(n-3);
}

int main(void) {
  cout<<stairs(3)<<'\n';
  cout<<stairs(4)<<'\n';
  cout<<stairs(5)<<'\n';
  return 0;
}