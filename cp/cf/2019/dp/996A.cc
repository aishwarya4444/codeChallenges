/*
https://codeforces.com/problemset/problem/996/A
*/

#include<iostream>
#include<vector>
using namespace std;

int main() {
  int count=0, n, i;
  vector<int> denom = {1 ,5, 10, 20, 100};
  cin>>n;

  for(i=denom.size()-1; i>=0; i--) {
    count += n/denom[i];
    n %= denom[i];
  }

  cout<<count<<endl;
  
  return 0;
}
