// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5740874747084800

#include<iostream>
using namespace std;

int fib(int n) {
  return n<2 ? n : fib(n-1)+fib(n-2);
}

int main(void) {
  cout<<fib(5)<<'\n';
  cout<<fib(6)<<'\n';
  cout<<fib(7)<<'\n';
  return 0;
}