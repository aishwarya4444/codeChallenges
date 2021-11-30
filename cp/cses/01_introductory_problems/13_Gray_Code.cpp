/*
https://cses.fi/problemset/task/2205
*/

#include <bits/stdc++.h>
using namespace std;

void print(int i, int n) {
  int mask = 1;
  string res = "";

  while(n--) {
    res += (i&mask) ? to_string(1) : to_string(0);
    mask <<= 1;
  }

  reverse(res.begin(), res.end());
  cout<<res<<endl;
}

void printUsingBitset(int i, int n) {
  bitset<32> num(i);
  string res = num.to_string();
  cout<<res.substr(32-n)<<endl;
}

int main(){

  int n;

  cin>>n;

  for(int i=0; i<(1<<n); i++) {
    // print(i^(i>>1), n);
    printUsingBitset(i^(i>>1), n);
  }

  return 0;
}
