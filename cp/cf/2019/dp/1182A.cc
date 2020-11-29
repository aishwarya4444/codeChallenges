/*
https://codeforces.com/problemset/problem/1182/A
*/

#include<iostream>
#include<vector>
using namespace std;
int main() {
  int n, res=1;
  cin>>n;
  if(n%2) {
    res = 0;
  } else {
    n /= 2;
    while(n--) {
      res *= 2;
    }
  }
  cout<<res<<endl;
  return 0;
}
